/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * $URL$
 * $Id$
 *
 */

#include "common/endian.h"
#include "common/savefile.h"
#include "graphics/dither.h"

#include "gob/gob.h"
#include "gob/video.h"
#include "gob/util.h"
#include "gob/draw.h"
#include "gob/global.h"

namespace Gob {

Video_v6::Video_v6(GobEngine *vm) : Video_v2(vm) {
}

void Video_v6::setPrePalette() {
	byte *tpal = (byte *)_vm->_draw->_vgaPalette;
	const byte *fpal = (const byte *)_ditherPalette;

	for (int i = 0; i < 256; i++) {
		byte r, g, b;

		Graphics::PaletteLUT::YUV2RGB(fpal[i * 3 + 0], fpal[i * 3 + 1], fpal[i * 3 + 2],
		                              r, g, b);

		tpal[i * 3 + 0] = r >> 2;
		tpal[i * 3 + 1] = g >> 2;
		tpal[i * 3 + 2] = b >> 2;
	}
	_vm->_global->_pPaletteDesc->vgaPal = _vm->_draw->_vgaPalette;
	_vm->_video->setFullPalette(_vm->_global->_pPaletteDesc);

}

void Video_v6::init() {
	initOSD();

	buildPalLUT();
}

void Video_v6::buildPalLUT() {
	char text[30];

	_palLUT->setPalette(_ditherPalette, Graphics::PaletteLUT::kPaletteYUV, 8, 0);

	sprintf(text, "Building palette table");
	drawOSDText(text);

	for (int i = 0; (i < 32) && !_vm->shouldQuit(); i++)
		_palLUT->buildNext();
}

char Video_v6::spriteUncompressor(byte *sprBuf, int16 srcWidth, int16 srcHeight,
	    int16 x, int16 y, int16 transp, SurfaceDesc &destDesc) {
	_vm->validateVideoMode(destDesc._vidMode);

	if ((sprBuf[0] == 1) && (sprBuf[1] == 3)) {
		drawPacked(sprBuf, x, y, destDesc);
		return 1;
	}

	if (srcWidth & 0xC000) {
		warning("Playtoons Stub: srcWidth & 0xC000 == %04X", srcWidth & 0xC000);
		srcWidth &= 0x3FFF;
	}

	if ((sprBuf[0] == 1) && (sprBuf[1] == 2)) {
		if (Video_v2::spriteUncompressor(sprBuf, srcWidth, srcHeight, x, y, transp, destDesc))
			return 1;

		_vm->validateVideoMode(destDesc._vidMode);

		_videoDriver->drawPackedSprite(sprBuf, srcWidth, srcHeight, x, y, transp, destDesc);
		return 1;
	}

	warning("Urban Stub: spriteUncompressor(), sprBuf[0,1,2] = %d,%d,%d",
			sprBuf[0], sprBuf[1], sprBuf[2]);
	return 1;
}

void Video_v6::fillRect(SurfaceDesc &dest,
		int16 left, int16 top, int16 right, int16 bottom, int16 color) {

	if (!(color & 0xFF00)) {
		Video::fillRect(dest, left, top, right, bottom, color);
		return;
	}

	if (!(color & 0x0100)) {
		Video::fillRect(dest, left, top, right, bottom, color);
		return;
	}

	if (_doRangeClamp) {
		if (left > right)
			SWAP(left, right);
		if (top > bottom)
			SWAP(top, bottom);

		if ((left >= dest.getWidth()) || (right < 0) ||
		    (top >= dest.getHeight()) || (bottom < 0))
			return;

		left = CLIP(left, (int16)0, (int16)(dest.getWidth() - 1));
		top = CLIP(top, (int16)0, (int16)(dest.getHeight() - 1));
		right = CLIP(right, (int16)0, (int16)(dest.getWidth() - 1));
		bottom = CLIP(bottom, (int16)0, (int16)(dest.getHeight() - 1));
	}

	byte strength = 16 - (((uint16) color) >> 12);
	shadeRect(dest, left, top, right, bottom, color, strength);
}

void Video_v6::shadeRect(SurfaceDesc &dest,
		int16 left, int16 top, int16 right, int16 bottom, byte color, byte strength) {

	int width  = right  - left + 1;
	int height = bottom - top  + 1;
	int dWidth = dest.getWidth();
	byte *vidMem = dest.getVidMem() + dWidth * top + left;

	byte sY, sU, sV;
	_palLUT->getEntry(color, sY, sU, sV);

	int shadeY = sY * (16 - strength);
	int shadeU = sU * (16 - strength);
	int shadeV = sV * (16 - strength);

	Graphics::SierraLight *dither =
		new Graphics::SierraLight(width, _palLUT);

	for (int i = 0; i < height; i++) {
		byte *d = vidMem;

		for (int j = 0; j < width; j++) {
			byte dY, dU, dV;
			byte dC = *d;

			_palLUT->getEntry(dC, dY, dU, dV);

			dY = CLIP<int>((shadeY + strength * dY) >> 4, 0, 255);
			dU = CLIP<int>((shadeU + strength * dU) >> 4, 0, 255);
			dV = CLIP<int>((shadeV + strength * dV) >> 4, 0, 255);

			*d++ = dither->dither(dY, dU, dV, j);
		}

		dither->nextLine();
		vidMem += dWidth;
	}

	delete dither;
}

void Video_v6::drawPacked(const byte *sprBuf, int16 x, int16 y, SurfaceDesc &surfDesc) {
	const byte *data = sprBuf + 2;

	int16 width = READ_LE_UINT16(data);
	int16 height = READ_LE_UINT16(data + 2);
	data += 4;

	const byte *srcData = data;
	byte *uncBuf = 0;

	if (*srcData++ != 0) {
		uint32 size = READ_LE_UINT32(data);

		uncBuf = new byte[size];

		//spriteUncompressor(data, buf);
		warning("Urban Stub: drawPacked: spriteUncompressor(data, uncBuf)");

		srcData = uncBuf;
	}

	drawYUVData(srcData, surfDesc, width, height, x, y);

	delete[] uncBuf;
}

void Video_v6::drawYUVData(const byte *srcData, SurfaceDesc &destDesc,
		int16 width, int16 height, int16 x, int16 y) {

	int16 dataWidth = width;
	int16 dataHeight = height;

	if (dataWidth & 0xF)
		dataWidth = (dataWidth & 0xFFF0) + 16;
	if (dataHeight & 0xF)
		dataHeight = (dataHeight & 0xFFF0) + 16;

	const byte *dataY = srcData;
	const byte *dataU = dataY +  (dataWidth * dataHeight);
	const byte *dataV = dataU + ((dataWidth * dataHeight) >> 4);

	drawYUV(destDesc, x, y, dataWidth, dataHeight, width, height, dataY, dataU, dataV);

}

void Video_v6::drawYUV(SurfaceDesc &destDesc, int16 x, int16 y,
		int16 dataWidth, int16 dataHeight, int16 width, int16 height,
		const byte *dataY, const byte *dataU, const byte *dataV) {

	byte *vidMem = destDesc.getVidMem() + y * destDesc.getWidth() + x;

	if ((x + width - 1) >= destDesc.getWidth())
		width = destDesc.getWidth() - x;
	if ((y + height - 1) >= destDesc.getHeight())
		height = destDesc.getHeight() - y;

	Graphics::SierraLight *dither =
		new Graphics::SierraLight(width, _palLUT);

	for (int i = 0; i < height; i++) {
		byte *dest = vidMem;
		const byte *srcY = dataY +  i       *  dataWidth;
		const byte *srcU = dataU + (i >> 2) * (dataWidth >> 2);
		const byte *srcV = dataV + (i >> 2) * (dataWidth >> 2);

		for (int j = 0; j < (width >> 2); j++, srcU++, srcV++) {
			for (int n = 0; n < 4; n++, dest++, srcY++) {
				byte dY = *srcY << 1, dU = *srcU << 1, dV = *srcV << 1;

				*dest = (dY == 0) ? 0 : dither->dither(dY, dU, dV, j * 4 + n);
			}
		}

		dither->nextLine();
		vidMem += destDesc.getWidth();
	}

	delete dither;
}

const byte Video_v6::_ditherPalette[768] = {
	0x00,0x80,0x80,0x26,0x6B,0xC0,0x4B,0x56,0x4B,0x71,0x41,0x8B,
	0x0E,0xC0,0x76,0x34,0xAB,0xB6,0x59,0x96,0x41,0xBE,0x81,0x81,
	0xCF,0x77,0x75,0xC1,0x9B,0x6C,0x7F,0x81,0x81,0x7F,0x81,0x81,
	0x0A,0x8C,0x8A,0x0A,0xB0,0x79,0x0E,0x9D,0x76,0x0E,0x79,0x76,
	0x10,0x77,0x75,0x09,0x7B,0x8B,0x16,0x74,0xA6,0x16,0x74,0xA6,
	0x12,0x91,0x93,0x13,0xB5,0x72,0x1B,0x9E,0x6D,0x1A,0x7A,0x6D,
	0x1C,0x71,0x6C,0x1B,0x72,0x8C,0x1B,0x71,0xAE,0x1B,0x71,0xAE,
	0x21,0x93,0x93,0x21,0xB8,0x6F,0x27,0xA3,0x64,0x27,0x7F,0x65,
	0x29,0x69,0x68,0x28,0x69,0x8E,0x23,0x6F,0xB7,0x2A,0x69,0xB2,
	0x36,0x94,0x92,0x35,0xB9,0x6E,0x35,0xA6,0x5D,0x34,0x80,0x5D,
	0x39,0x61,0x6B,0x3A,0x60,0x8F,0x34,0x6E,0xB9,0x39,0x60,0xB5,
	0x46,0x93,0x95,0x48,0xB6,0x6F,0x45,0xA6,0x5C,0x47,0x80,0x5C,
	0x4B,0x56,0x6D,0x4B,0x56,0x91,0x47,0x6F,0xB7,0x4A,0x57,0xB5,
	0x5A,0x94,0x92,0x59,0xB9,0x6E,0x59,0xA6,0x5D,0x59,0x82,0x5D,
	0x5B,0x4D,0x6D,0x5A,0x4E,0x92,0x5B,0x6F,0xB7,0x5C,0x4D,0xB6,
	0x6D,0x94,0x93,0x6D,0xB8,0x6F,0x6D,0xA5,0x5D,0x6C,0x7F,0x5E,
	0x6C,0x4A,0x70,0x6D,0x4A,0x94,0x6C,0x6E,0xB9,0x6C,0x4A,0xBA,
	0x7E,0x94,0x93,0x80,0xB6,0x6F,0x7D,0xA6,0x5D,0x7F,0x81,0x5B,
	0x7F,0x4A,0x6F,0x7F,0x4A,0x92,0x7E,0x6F,0xB7,0x7E,0x4B,0xB7,
	0x92,0x94,0x93,0x90,0xB8,0x6F,0x91,0xA5,0x5C,0x90,0x81,0x5D,
	0x91,0x4B,0x6D,0x91,0x4C,0x93,0x93,0x6F,0xB7,0x92,0x4B,0xB7,
	0xA5,0x91,0x93,0xA2,0xB2,0x6F,0xA5,0xA6,0x5D,0xA4,0x80,0x5D,
	0xA3,0x4A,0x6F,0xA4,0x49,0x93,0xA4,0x6F,0xB9,0xA3,0x4B,0xB9,
	0xB6,0x94,0x93,0xB4,0xA9,0x71,0xB6,0xA5,0x5C,0xB8,0x80,0x5C,
	0xB7,0x4B,0x6F,0xB6,0x4C,0x93,0xB5,0x70,0xB3,0xB5,0x4C,0xB3,
	0xC9,0x93,0x92,0xC3,0xA0,0x72,0xC7,0x9E,0x5E,0xC9,0x82,0x5D,
	0xCA,0x4B,0x6E,0xCA,0x4B,0x93,0xC2,0x73,0xA9,0xC2,0x4F,0xA9,
	0xDD,0x92,0x93,0xD4,0x97,0x74,0xD9,0x94,0x60,0xDD,0x80,0x5E,
	0xDB,0x4B,0x6F,0xDD,0x4A,0x93,0xCE,0x76,0xA1,0xCE,0x52,0xA1,
	0xE8,0x8B,0x8E,0xE6,0x8C,0x76,0xE7,0x8C,0x61,0xE6,0x86,0x62,
	0xE3,0x51,0x78,0xEA,0x4D,0x8D,0xDC,0x79,0x97,0xDC,0x55,0x97,
	0xFA,0x81,0x81,0xF8,0x82,0x83,0xF4,0x85,0x77,0xF2,0x79,0x79,
	0xF4,0x65,0x86,0xF8,0x75,0x83,0xEF,0x87,0x89,0xF0,0x67,0x89,
	0xEE,0x81,0x81,0xE8,0x8B,0x85,0xED,0x88,0x71,0xEA,0x71,0x73,
	0xEE,0x5D,0x81,0xEA,0x71,0x8D,0xE4,0x87,0x91,0xE4,0x63,0x91,
	0xDB,0x81,0x81,0xD7,0x95,0x83,0xDB,0x93,0x6F,0xDB,0x6F,0x6F,
	0xDC,0x5C,0x80,0xDD,0x6E,0x93,0xD7,0x83,0x9B,0xD6,0x5F,0x9B,
	0xCA,0x81,0x81,0xC8,0x9D,0x82,0xC8,0x94,0x6E,0xCA,0x6F,0x6E,
	0xC9,0x5D,0x81,0xCA,0x6F,0x93,0xC9,0x82,0xA5,0xC8,0x5E,0xA5,
	0xB6,0x81,0x81,0xB6,0xA5,0x80,0xB7,0x93,0x6F,0xB7,0x6F,0x6F,
	0xB6,0x5D,0x81,0xB6,0x70,0x93,0xB8,0x80,0xA5,0xB7,0x5C,0xA5,
	0xA3,0x81,0x81,0xA4,0xA7,0x81,0xA3,0x92,0x6F,0xA3,0x6E,0x6F,
	0xA5,0x5C,0x7F,0xA5,0x6D,0x93,0xA4,0x80,0xA5,0xA4,0x5C,0xA5,
	0x92,0x81,0x81,0x93,0xA5,0x81,0x90,0x94,0x6F,0x92,0x6F,0x6D,
	0x92,0x5D,0x81,0x92,0x70,0x93,0x91,0x82,0xA7,0x91,0x5E,0xA7,
	0x7F,0x81,0x81,0x7F,0xA5,0x81,0x80,0x92,0x70,0x7F,0x6E,0x6F,
	0x7F,0x5D,0x81,0x7D,0x70,0x93,0x80,0x80,0xA5,0x80,0x5C,0xA5,
	0x6B,0x81,0x81,0x6C,0xA7,0x80,0x6D,0x94,0x6F,0x6C,0x6E,0x6F,
	0x6D,0x5B,0x80,0x6D,0x6E,0x93,0x6C,0x81,0xA5,0x6C,0x5D,0xA5,
	0x5A,0x81,0x81,0x5A,0xA5,0x81,0x59,0x95,0x6E,0x5A,0x6F,0x6E,
	0x5B,0x5D,0x81,0x59,0x70,0x93,0x5A,0x81,0xA7,0x5A,0x5D,0xA7,
	0x47,0x81,0x81,0x47,0xA5,0x80,0x47,0x92,0x6F,0x47,0x6E,0x6F,
	0x46,0x5D,0x81,0x46,0x6F,0x95,0x49,0x81,0xA5,0x48,0x5D,0xA5,
	0x32,0x81,0x81,0x33,0xA7,0x81,0x35,0x95,0x6E,0x34,0x6F,0x6F,
	0x36,0x62,0x7E,0x35,0x6E,0x93,0x34,0x80,0xA5,0x36,0x62,0xA4,
	0x23,0x81,0x81,0x23,0xA5,0x80,0x20,0x94,0x6F,0x22,0x6F,0x6D,
	0x26,0x6B,0x7E,0x21,0x6F,0x93,0x22,0x82,0xA7,0x25,0x6C,0xA4,
	0x0E,0x81,0x81,0x0F,0xA5,0x81,0x13,0x91,0x73,0x15,0x75,0x71,
	0x14,0x75,0x7D,0x11,0x77,0x93,0x15,0x7D,0xA1,0x16,0x74,0xA1,
	0x00,0x80,0x80,0x07,0xA0,0x7B,0x05,0x8F,0x7D,0x09,0x7B,0x7A,
	0x07,0x7D,0x7B,0x07,0x7C,0x8C,0x0E,0x78,0x98,0x0E,0x78,0x98,
	0x7F,0x81,0x81,0x80,0x83,0x81,0xF7,0x7C,0x84,0x9E,0x83,0x80,
	0x7F,0x81,0x81,0x4B,0x56,0xFE,0x93,0x2D,0x17,0xDE,0x03,0x95,
	0x1C,0xFE,0x6C,0x67,0xD4,0xEA,0xAF,0xAB,0x03,0xFA,0x81,0x81
};

} // End of namespace Gob
