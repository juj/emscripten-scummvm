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
 */

#include "neverhood/module2200.h"
#include "neverhood/module1000.h"
#include "neverhood/module1200.h"
#include "neverhood/gamemodule.h"
#include "neverhood/diskplayerscene.h"

namespace Neverhood {

Module2200::Module2200(NeverhoodEngine *vm, Module *parentModule, int which)
	: Module(vm, parentModule) {
	
	debug("Create Module2200(%d)", which);

	// TODO: Music18hList_add(0x11391412, 0x601C908C); 

	if (which < 0) {
		switch (_vm->gameState().sceneNum) {
		default:
			createScene2201(-1);
			break;
		case 1:
			createScene2202(-1);
			break;
		case 2:
			createScene2203(-1);
			break;
		case 3:
			createScene2204(-1);
			break;
		case 4:
			createScene2205(-1);
			break;
		case 5:
			createScene2206(-1);
			break;
		case 6:
			createScene2207(-1);
			break;
		case 7:
			createScene2208(-1);
			break;
		case 8:
			createScene2209(-1);
			break;
		case 9:
			createScene2210(-1);
			break;
		case 10:
			createScene2211(-1);
			break;
		case 11:
			createScene2212(-1);
			break;
		case 12:
			createScene2213(-1);
			break;
		case 13:
			createScene2214(-1);
			break;
		case 14:
			createScene2215(-1);
			break;
		case 15:
			createScene2216(-1);
			break;
		case 16:
			createScene2217(-1);
			break;
		case 17:
			createScene2218(-1);
			break;
		case 18:
			createScene2219(-1);
			break;
		case 19:
			createScene2220(-1);
			break;
		case 20:
			createScene2221(-1);
			break;
		case 21:
			createScene2222(-1);
			break;
		case 22:
			createScene2223(-1);
			break;
		case 23:
			createScene2224(-1);
			break;
		case 24:
			createScene2225(-1);
			break;
		case 25:
			createScene2226(-1);
			break;
		case 26:
			createScene2227(-1);
			break;
		case 27:
			createScene2228(-1);
			break;
		case 28:
			createScene2229(-1);
			break;
		case 29:
			createScene2230(-1);
			break;
		case 30:
			createScene2231(-1);
			break;
		case 31:
			createScene2232(-1);
			break;
		case 32:
			createScene2233(-1);
			break;
		case 33:
			createScene2234(-1);
			break;
		case 34:
			createScene2235(-1);
			break;
		case 35:
			createScene2236(-1);
			break;
		case 36:
			createScene2237(-1);
			break;
		case 37:
			createScene2238(-1);
			break;
		case 38:
			createScene2239(-1);
			break;
		case 39:
			createScene2240(-1);
			break;
		case 40:
			createScene2241(-1);
			break;
		case 41:
			createScene2242(-1);
			break;
		case 42:
			createScene2243(-1);
			break;
		case 43:
			createScene2244(-1);
			break;
		case 44:
			createScene2245(-1);
			break;
		case 45:
			createScene2246(-1);
			break;
		case 46:
			createScene2247(-1);
			break;
		case 47:
			createScene2248(-1);
			break;
		}
	} else {
		createScene2201(0);
	}

}

Module2200::~Module2200() {
	// TODO Sound1ChList_sub_407A50(0x11391412);
}

void Module2200::createScene2201(int which) {
	_vm->gameState().sceneNum = 0;
	_childObject = new Scene2201(_vm, this, which);
	SetUpdateHandler(&Module2200::updateScene2201);
}

void Module2200::createScene2202(int which) {
	// TODO Music18hList_play(0x601C908C, 0, 2, 1);
	_vm->gameState().sceneNum = 1;
	_childObject = new Scene2202(_vm, this, which);
	SetUpdateHandler(&Module2200::updateScene2202);
}

void Module2200::createScene2203(int which) {
	// TODO Music18hList_play(0x601C908C, 0, 2, 1);
	_vm->gameState().sceneNum = 2;
	_childObject = new Scene2203(_vm, this, which);
	SetUpdateHandler(&Module2200::updateScene2203);
}

void Module2200::createScene2204(int which) {
	_vm->gameState().sceneNum = 3;
	// TODO Music18hList_stop(0x601C908C, 0, 2);
	_childObject = new DiskplayerScene(_vm, this, 3);
	SetUpdateHandler(&Module2200::updateScene2204);
}
			
void Module2200::createScene2205(int which) {
	_vm->gameState().sceneNum = 4;
	// TODO Music18hList_stop(0x601C908C, 0, 2);
	_childObject = new Scene2205(_vm, this, which);
	SetUpdateHandler(&Module2200::updateScene2205);
}
			
void Module2200::createScene2206(int which) {
	_vm->gameState().sceneNum = 5;
	// TODO Music18hList_stop(0x601C908C, 0, 2);
	_childObject = new Scene2206(_vm, this, which);
	SetUpdateHandler(&Module2200::updateScene2206);
}
			
void Module2200::createScene2207(int which) {
	_vm->gameState().sceneNum = 6;
	_childObject = new Scene2207(_vm, this, which);
	SetUpdateHandler(&Module2200::updateScene2207);
}
			
void Module2200::createScene2208(int which) {
	if (which >= 0)
		_vm->gameState().which = _vm->gameState().sceneNum; 
	_vm->gameState().sceneNum = 7;
	_childObject = new Scene2208(_vm, this, which);
	SetUpdateHandler(&Module2200::updateScene2208);
}
			
void Module2200::createScene2209(int which) {
}
			
void Module2200::createScene2210(int which) {
}
			
void Module2200::createScene2211(int which) {
}
			
void Module2200::createScene2212(int which) {
}
			
void Module2200::createScene2213(int which) {
}
			
void Module2200::createScene2214(int which) {
}
			
void Module2200::createScene2215(int which) {
}
			
void Module2200::createScene2216(int which) {
}
			
void Module2200::createScene2217(int which) {
}
			
void Module2200::createScene2218(int which) {
}
			
void Module2200::createScene2219(int which) {
}
			
void Module2200::createScene2220(int which) {
}
			
void Module2200::createScene2221(int which) {
}
			
void Module2200::createScene2222(int which) {
}
			
void Module2200::createScene2223(int which) {
}
			
void Module2200::createScene2224(int which) {
}
			
void Module2200::createScene2225(int which) {
}
			
void Module2200::createScene2226(int which) {
}
			
void Module2200::createScene2227(int which) {
}
			
void Module2200::createScene2228(int which) {
}
			
void Module2200::createScene2229(int which) {
}
			
void Module2200::createScene2230(int which) {
}
			
void Module2200::createScene2231(int which) {
}
			
void Module2200::createScene2232(int which) {
}
			
void Module2200::createScene2233(int which) {
}
			
void Module2200::createScene2234(int which) {
}
			
void Module2200::createScene2235(int which) {
}
			
void Module2200::createScene2236(int which) {
}
			
void Module2200::createScene2237(int which) {
}
			
void Module2200::createScene2238(int which) {
}
			
void Module2200::createScene2239(int which) {
}
			
void Module2200::createScene2240(int which) {
}
			
void Module2200::createScene2241(int which) {
}
			
void Module2200::createScene2242(int which) {
}
			
void Module2200::createScene2243(int which) {
}
			
void Module2200::createScene2244(int which) {
}
			
void Module2200::createScene2245(int which) {
}
			
void Module2200::createScene2246(int which) {
}
			
void Module2200::createScene2247(int which) {
}
			
void Module2200::createScene2248(int which) {
}
			
void Module2200::updateScene2201() {
	_childObject->handleUpdate();
	if (_done) {
		_done = false;
		delete _childObject;
		_childObject = NULL;
		if (_field20 == 1) {
			createScene2203(0);
		} else if (_field20 == 2) {
			createScene2202(0);
		} else {
			_parentModule->sendMessage(0x1009, 0, this);
		}
	}
}
			
void Module2200::updateScene2202() {
	_childObject->handleUpdate();
	if (_done) {
		_done = false;
		delete _childObject;
		_childObject = NULL;
		createScene2201(2);
	}
}

void Module2200::updateScene2203() {
	_childObject->handleUpdate();
	if (_done) {
		_done = false;
		delete _childObject;
		_childObject = NULL;
		if (_field20 == 1) {
			createScene2205(0);
			_childObject->handleUpdate();
		} else if (_field20 == 2) {
			createScene2204(0);
			_childObject->handleUpdate();
		} else {
			createScene2201(1);
			_childObject->handleUpdate();
		}
	}
}
			
void Module2200::updateScene2204() {
	_childObject->handleUpdate();
	if (_done) {
		_done = false;
		delete _childObject;
		_childObject = NULL;
		createScene2203(2);
	}
}
			
void Module2200::updateScene2205() {
	_childObject->handleUpdate();
	if (_done) {
		_done = false;
		delete _childObject;
		_childObject = NULL;
		if (_field20 == 1) {
			createScene2206(0);
			_childObject->handleUpdate();
		} else if (_field20 == 2) {
			createScene2205(2);
			_childObject->handleUpdate();
		} else {
			createScene2203(1);
			_childObject->handleUpdate();
		}
	}
}
			
void Module2200::updateScene2206() {
	_childObject->handleUpdate();
	if (_done) {
		_done = false;
		delete _childObject;
		_childObject = NULL;
		if (_field20 == 1) {
			createScene2247(0);
			_childObject->handleUpdate();
		} else if (_field20 == 2) {
			createScene2207(0);
			_childObject->handleUpdate();
		} else if (_field20 == 3) {
			createScene2209(0);
			_childObject->handleUpdate();
		} else {
			createScene2205(1);
			_childObject->handleUpdate();
		}
	}
}
			
void Module2200::updateScene2207() {
	_childObject->handleUpdate();
	if (_done) {
		_done = false;
		delete _childObject;
		_childObject = NULL;
		createScene2206(2);
		_childObject->handleUpdate();
	}
}
			
void Module2200::updateScene2208() {
	_childObject->handleUpdate();
	if (_done) {
		_done = false;
		delete _childObject;
		_childObject = NULL;
		// TODO
		createScene2206(2);
		_childObject->handleUpdate();
	}
}
			
void Module2200::updateScene2209() {
}
			
void Module2200::updateScene2210() {
}
			
void Module2200::updateScene2211() {
}
			
void Module2200::updateScene2212() {
}
			
void Module2200::updateScene2213() {
}
			
void Module2200::updateScene2214() {
}
			
void Module2200::updateScene2215() {
}
			
void Module2200::updateScene2216() {
}
			
void Module2200::updateScene2217() {
}
			
void Module2200::updateScene2218() {
}
			
void Module2200::updateScene2219() {
}
			
void Module2200::updateScene2220() {
}
			
void Module2200::updateScene2221() {
}
			
void Module2200::updateScene2222() {
}
			
void Module2200::updateScene2223() {
}
			
void Module2200::updateScene2224() {
}
			
void Module2200::updateScene2225() {
}
			
void Module2200::updateScene2226() {
}
			
void Module2200::updateScene2227() {
}
			
void Module2200::updateScene2228() {
}
			
void Module2200::updateScene2229() {
}
			
void Module2200::updateScene2230() {
}
			
void Module2200::updateScene2231() {
}
			
void Module2200::updateScene2232() {
}
			
void Module2200::updateScene2233() {
}
			
void Module2200::updateScene2234() {
}
			
void Module2200::updateScene2235() {
}
			
void Module2200::updateScene2236() {
}
			
void Module2200::updateScene2237() {
}
			
void Module2200::updateScene2238() {
}
			
void Module2200::updateScene2239() {
}
			
void Module2200::updateScene2240() {
}
			
void Module2200::updateScene2241() {
}
			
void Module2200::updateScene2242() {
}
			
void Module2200::updateScene2243() {
}
			
void Module2200::updateScene2244() {
}
			
void Module2200::updateScene2245() {
}
			
void Module2200::updateScene2246() {
}
			
void Module2200::updateScene2247() {
}
			
void Module2200::updateScene2248() {
}

// Scene2201

AsScene2201CeilingFan::AsScene2201CeilingFan(NeverhoodEngine *vm)
	: AnimatedSprite(vm, 1100) {

	_x = 403;
	_y = 259;
	createSurface(100, 233, 96);
	setFileHash(0x8600866, 0, -1);
	SetUpdateHandler(&AnimatedSprite::update);
}

AsScene2201Door::AsScene2201Door(NeverhoodEngine *vm, Klayman *klayman, Sprite *doorLightSprite, bool flag1)
	: AnimatedSprite(vm, 1100), _soundResource(vm), _klayman(klayman), _doorLightSprite(doorLightSprite), 
	_countdown(0), _doorOpen(flag1) {

	_x = 408;
	_y = 290;	
	createSurface(900, 63, 266);
	SetUpdateHandler(&AsScene2201Door::update);
	SetMessageHandler(&AsScene2201Door::handleMessage);
	if (_doorOpen) {
		setFileHash(0xE2CB0412, -1, -1);
		_countdown = 48;
		_newHashListIndex = -2;
	} else {
		setFileHash(0xE2CB0412, 0, -1);
		_newHashListIndex = 0;
		_doorLightSprite->getSurface()->setVisible(false);
	}
}

void AsScene2201Door::update() {
	if (_countdown != 0 && _doorOpen && (--_countdown == 0)) {
		stCloseDoor();
	}
	AnimatedSprite::update();
}

uint32 AsScene2201Door::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Sprite::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x100D:
		if (param.asInteger() == 0x11001090) {
			if (_doorOpen)
				_doorLightSprite->getSurface()->setVisible(true);
		} else if (param.asInteger() == 0x11283090) {
			if (!_doorOpen)
				_doorLightSprite->getSurface()->setVisible(false);
		}
		break;
	case 0x2000:
		if (_doorOpen)
			_countdown = 144;
		messageResult = _doorOpen ? 1 : 0;
		break;
	case 0x3002:
		removeCallbacks();
		break;
	case 0x4808:
		_countdown = 144;
		if (!_doorOpen)
			stOpenDoor();
		break;
	}
	return messageResult;
}

void AsScene2201Door::stOpenDoor() {
	_doorOpen = true;
	setFileHash(0xE2CB0412, 0, -1);
	_newHashListIndex = -2;
	_soundResource.play(calcHash("fxDoorOpen33"));
}

void AsScene2201Door::stCloseDoor() {
	_doorOpen = false;
	setFileHash(0xE2CB0412, -1, -1);
	_playBackwards = true;
	_newHashListIndex = 0;
	_soundResource.play(calcHash("fxDoorClose33"));
}

Class444::Class444(NeverhoodEngine *vm, int pointIndex, int spriteIndex)
	: StaticSprite(vm, 900) {
	
	_spriteResource.load2(kClass444FileHashes[spriteIndex]);
	createSurface(100, 16, 16);
	_drawRect.x = -(_spriteResource.getDimensions().width / 2);
	_drawRect.y = -(_spriteResource.getDimensions().height / 2);
	_drawRect.width = _spriteResource.getDimensions().width;
	_drawRect.height = _spriteResource.getDimensions().height;
	_x = kClass444Points[pointIndex].x;
	_y = kClass444Points[pointIndex].y;
	_needRefresh = true;
}

Scene2201::Scene2201(NeverhoodEngine *vm, Module *parentModule, int which)
	: Scene(vm, parentModule, true), _soundFlag(false) {

	Sprite *tempSprite;

	if (!getSubVar(0x40050052, 0x60400854)) {
		// TODO _vm->gameModule()->initScene2201Vars();
	}

	_surfaceFlag = true;
	SetMessageHandler(&Scene2201::handleMessage);
	SetUpdateHandler(&Scene2201::update);
	
	loadDataResource(0x04104242);
	loadHitRectList();

	_background = addBackground(new DirtyBackground(_vm, 0x40008208, 0, 0));
	_palette = new Palette(_vm, 0x40008208);
	_palette->usePalette();
	_mouseCursor = addSprite(new Mouse433(_vm, 0x0820C408, NULL));

	_asTape = addSprite(new AsScene1201Tape(_vm, this, 7, 1100, 459, 432, 0x9148A011));
	_vm->_collisionMan->addSprite(_asTape); 

	_ssDoorButton = addSprite(new Class426(_vm, this, 0xE4A43E29, 0xE4A43E29, 100, 0));
	
	for (uint32 i = 0; i < 9; i++) {
		if ((int16)getSubVar(0x484498D0, i) >= 0) {
			addSprite(new Class444(_vm, i, (int16)getSubVar(0x484498D0, i)));
		}
	}

	_rect1.y1 = 0;
	_rect1.x2 = 640;
	_rect2.x2 = 640;
	_rect2.y2 = 480;
	
	if (!getGlobalVar(0x404290D5)) {
		addSprite(new StaticSprite(_vm, 0x00026027, 900));
	}
	
	tempSprite = addSprite(new StaticSprite(_vm, 0x030326A0, 1100));
	_rect1.x1 = tempSprite->getSurface()->getDrawRect().x;
	
	addSprite(new StaticSprite(_vm, 0x811DA061, 1100));

	tempSprite = addSprite(new StaticSprite(_vm, 0x11180022, 1100));
	_rect2.x1 = tempSprite->getSurface()->getDrawRect().x;

	tempSprite = addSprite(new StaticSprite(_vm, 0x0D411130, 1100));
	_rect1.y2 = tempSprite->getSurface()->getDrawRect().y + tempSprite->getSurface()->getDrawRect().height;
	_rect2.y1 = tempSprite->getSurface()->getDrawRect().y + tempSprite->getSurface()->getDrawRect().height;
	
	_doorLightSprite = addSprite(new StaticSprite(_vm, 0xA4062212, 900));

	if (which < 0) {
		_klayman = new KmScene2201(_vm, this, 300, 427, &_rect1, 2);
		setMessageList(0x004B8118);
		_asDoor = addSprite(new AsScene2201Door(_vm, _klayman, _doorLightSprite, false));
	} else if (which == 1) {
		_klayman = new KmScene2201(_vm, this, 412, 393, &_rect1, 2);
		setMessageList(0x004B8130);
		_asDoor = addSprite(new AsScene2201Door(_vm, _klayman, _doorLightSprite, false));
	} else if (which == 2) {
		if (getGlobalVar(0xC0418A02)) {
			_klayman = new KmScene2201(_vm, this, 379, 427, &_rect1, 2);
			_klayman->setDoDeltaX(1);
		} else {
			_klayman = new KmScene2201(_vm, this, 261, 427, &_rect1, 2);
		}
		setMessageList(0x004B8178);
		_asDoor = addSprite(new AsScene2201Door(_vm, _klayman, _doorLightSprite, false));
	} else {
		NPoint pt = _dataResource.getPoint(0x0304D8DC);
		_klayman = new KmScene2201(_vm, this, pt.x, pt.y, &_rect1, 2);
		setMessageList(0x004B8120);
		_asDoor = addSprite(new AsScene2201Door(_vm, _klayman, _doorLightSprite, true));
	}
	addSprite(_klayman);
	
	addSprite(new AsScene2201CeilingFan(_vm));

	// TODO Sound1ChList_addSoundResource(0x04106220, 0x81212040, true);

}

Scene2201::~Scene2201() {
	setGlobalVar(0xC0418A02, _klayman->isDoDeltaX() ? 1 : 0);
	// TODO Sound1ChList_sub_407AF0(0x04106220);
}

void Scene2201::update() {
	Scene::update();
	if (!_soundFlag) {
		// TODO Sound1ChList_playLooping(0x81212040);
		_soundFlag = true;
	}
}

uint32 Scene2201::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	Scene::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x100D:
		if (param.asInteger() == 0x402064D8) {
			_klayman->sendEntityMessage(0x1014, _ssDoorButton, this);
		} else if (param.asInteger() == 0x35803198) {
			if (_asDoor->hasMessageHandler() && _asDoor->sendMessage(0x2000, 0, this)) {
				setMessageList(0x004B81A0);
			} else {
				setMessageList(0x004B81B8);
			} 
		} else if (param.asInteger() == 0x51445010) {
			if (getGlobalVar(0x404290D5)) {
				setMessageList(0x004B8108);
			} else {
				setMessageList(0x004B8150);
			}
		} else if (param.asInteger() == 0x1D203082) {
			setMessageList(0x004B8180);
		} else if (param.asInteger() == 0x00049091) {
			if (getGlobalVar(0x404290D5)) {
				setMessageList(0x004B8138);
			} else {
				setMessageList(0x004B8108);
			}
		}
		break;
	case 0x480B:
		if (sender == _ssDoorButton) {
			_asDoor->sendMessage(0x4808, 0, this);
		}
		break;
	case 0x4826:
		if (sender == _asTape) {
			_klayman->sendEntityMessage(0x1014, _asTape, this);
			setMessageList(0x004B81C8);
		}
		break;
	}
	return 0;
}

static const NPoint kSsScene2202PuzzleTilePoints[] = {
	{196, 105},
	{323, 102},
	{445, 106},
	{192, 216},
	{319, 220},
	{446, 216},
	{188, 320},
	{319, 319},
	{443, 322}
};

static const uint32 kSsScene2202PuzzleTileFileHashes1[] = {
	0xA500800C,
	0x2182910C,
	0x2323980C,
	0x23049084,
	0x21008080,
	0x2303900C,
	0x6120980C,
	0x2504D808
};

static const uint32 kSsScene2202PuzzleTileFileHashes2[] = {
	0x0AAD8080,
	0x0A290291,
	0x0A2BA398,
	0x822B8490,
	0x86298080,
	0x0A2B8390,
	0x0A69A098,
	0x0E2D84D8
};

SsScene2202PuzzleTile::SsScene2202PuzzleTile(NeverhoodEngine *vm, Scene *parentScene, int16 tileIndex, int16 value)
	: StaticSprite(vm, 900), _soundResource1(vm), _soundResource2(vm), _parentScene(parentScene),
	_value(value), _tileIndex(tileIndex), _isMoving(false) {
	
	SetUpdateHandler(&SsScene2202PuzzleTile::update);
	SetMessageHandler(&SsScene2202PuzzleTile::handleMessage);
	_spriteResource.load2(kSsScene2202PuzzleTileFileHashes2[_value]);
	if (_tileIndex >= 0 && _tileIndex <= 2) {
		createSurface(100, 128, 128);
	} else	if (_tileIndex >= 3 && _tileIndex <= 5) {
		createSurface(300, 128, 128);
	} else {
		createSurface(500, 128, 128);
	}
	_drawRect.x = -(_spriteResource.getDimensions().width / 2);
	_drawRect.y = -(_spriteResource.getDimensions().height / 2);
	_drawRect.width = _spriteResource.getDimensions().width;
	_drawRect.height = _spriteResource.getDimensions().height;
	_deltaRect = _drawRect;
	_x = kSsScene2202PuzzleTilePoints[_tileIndex].x;
	_y = kSsScene2202PuzzleTilePoints[_tileIndex].y;
	processDelta();
	_needRefresh = true;
	StaticSprite::update();
	_soundResource1.load(0x40958621);
	_soundResource2.load(0x51108241);
}

void SsScene2202PuzzleTile::update() {
	handleSpriteUpdate();
	StaticSprite::update();
}

uint32 SsScene2202PuzzleTile::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Sprite::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x1011:
		if (!_isMoving && !getGlobalVar(0x404290D5)) {
			_parentScene->sendMessage(0x2000, _tileIndex, this);
		}
		messageResult = 1;
		break;
	case 0x2001:
		_isMoving = true;
		moveTile(param.asInteger());
		break;
	}
	return messageResult;
}
				
void SsScene2202PuzzleTile::suMoveTileX() {

	bool done = false;

	if (_counterDirection) {
		if (_counter > 2)
			_counter -= 2;
	} else {
		if (_counter < 20)
			_counter += 2;
	}

	for (int16 i = 0; i < _counter; i++) {
		_x += _xIncr;
		_errValue += _yDelta;
		if (_errValue >= _xDelta) {
			_errValue -= _xDelta;
			_y += _yIncr;
		}
		if (_x == _newX && _y == _newY) {
			done = true;
			break;
		}
		if (_x == _xFlagPos)
			_counterDirection = true;
	}
	
	if (done) {
		stopMoving();			
	}

	processDelta();

}

void SsScene2202PuzzleTile::suMoveTileY() {

	bool done = false;

	if (_counterDirection) {
		if (_counter > 2)
			_counter -= 2;
	} else {
		if (_counter < 20)
			_counter += 2;
	}

	for (int16 i = 0; i < _counter; i++) {
		_y += _yIncr;
		_errValue += _xDelta;
		if (_errValue >= _yDelta) {
			_errValue -= _yDelta;
			_x += _xIncr;
		}
		if (_x == _newX && _y == _newY) {
			done = true;
			break;
		}
		if (_x == _xFlagPos)
			_counterDirection = true;
	}
	
	if (done) {
		stopMoving();			
	}

	processDelta();

}

void SsScene2202PuzzleTile::moveTile(int16 newTileIndex) {

	_spriteResource.load2(kSsScene2202PuzzleTileFileHashes1[_value]);
	_drawRect.x = -(_spriteResource.getDimensions().width / 2);
	_drawRect.y = -(_spriteResource.getDimensions().height / 2);
	_drawRect.width = _spriteResource.getDimensions().width;
	_drawRect.height = _spriteResource.getDimensions().height;
	_needRefresh = true;

	setSubVar(0x484498D0, _tileIndex, (uint32)-1);
	setSubVar(0x484498D0, newTileIndex, (uint32)_value);
	
	_tileIndex = newTileIndex;
	
	_errValue = 0;
	_counterDirection = false;
	_counter = 0;

	_newX = kSsScene2202PuzzleTilePoints[newTileIndex].x;
	_newY = kSsScene2202PuzzleTilePoints[newTileIndex].y;

	if (_x == _newX && _y == _newY)
		return;

	if (_x <= _newX) {
		if (_y <= _newY) {
			_xDelta = _newX - _x;
			_yDelta = _newY - _y;
			_xIncr = 1;
			_yIncr = 1;
		} else {
			_xDelta = _newX - _x;
			_yDelta = _y - _newY;
			_xIncr = 1;
			_yIncr = -1;
		}
	} else {
		if (_y <= _newY) {
			_xDelta = _x - _newX;
			_yDelta = _newY - _y;
			_xIncr = -1;
			_yIncr = 1;
		} else {
			_xDelta = _x - _newX;
			_yDelta = _y - _newY;
			_xIncr = -1;
			_yIncr = -1;
		}
	}

	if (_xDelta > _yDelta) {
		SetSpriteCallback(&SsScene2202PuzzleTile::suMoveTileX);
		if (_xIncr > 0) {
			if (_newX - _x >= 180)
				_xFlagPos = _newX - 90;
			else
				_xFlagPos = _x + _newX / 2;				
		} else {
			if (_x - _newX >= 180)
				_xFlagPos = _x + 90;
			else
				_xFlagPos = _x / 2 + _newX;
		}
		_soundResource1.play();
	} else {
		SetSpriteCallback(&SsScene2202PuzzleTile::suMoveTileY);
		if (_yIncr > 0) {
			if (_newY - _y >= 180)
				_xFlagPos = _newY - 90;
			else
				_xFlagPos = _y + _newY / 2;				
		} else {
			if (_y - _newY >= 180)
				_xFlagPos = _y + 90;
			else
				_xFlagPos = _y / 2 + _newY;
		}
		_soundResource2.play();
	}
	
}

void SsScene2202PuzzleTile::stopMoving() {
	_spriteResource.load2(kSsScene2202PuzzleTileFileHashes2[_value]);
	_drawRect.x = -(_spriteResource.getDimensions().width / 2);
	_drawRect.y = -(_spriteResource.getDimensions().height / 2);
	_drawRect.width = _spriteResource.getDimensions().width;
	_drawRect.height = _spriteResource.getDimensions().height;
	_needRefresh = true;
	SetSpriteCallback(NULL);
	_isMoving = false;
	_parentScene->sendMessage(0x2002, _tileIndex, this);
}

Scene2202::Scene2202(NeverhoodEngine *vm, Module *parentModule, int which)
	: Scene(vm, parentModule, true), _soundResource1(vm), _soundResource2(vm),
	_isSolved(false), _leaveScene(false), _isTileMoving(false), _movingTileSprite(NULL), _doneMovingTileSprite(NULL) {

	Palette2 *palette2;

	// TODO initScene2201Vars();
	SetMessageHandler(&Scene2202::handleMessage);
	SetUpdateHandler(&Scene2202::update);

	_surfaceFlag = true;

	_background = addBackground(new DirtyBackground(_vm, 0x08100A0C, 0, 0));
	palette2 = new Palette2(_vm, 0x08100A0C);
	_palette = palette2;
	_palette->usePalette();
	addEntity(palette2);
	_mouseCursor = addSprite(new Mouse435(_vm, 0x00A08089, 20, 620));

	//DEBUG!
	for (uint32 index = 0; index < 9; index++)
		setSubVar(0x484498D0, index, 7 - index);

	for (uint32 index = 0; index < 9; index++) {
		int16 value = (int16)getSubVar(0x484498D0, index);
		if (value >= 0) {
			Sprite *puzzleTileSprite = addSprite(new SsScene2202PuzzleTile(_vm, this, index, value));
			_vm->_collisionMan->addSprite(puzzleTileSprite);
		}
	}

	addSprite(new StaticSprite(_vm, 0x55C043B8, 200));
	addSprite(new StaticSprite(_vm, 0x85500158, 400));
	addSprite(new StaticSprite(_vm, 0x25547028, 600));

	_soundResource1.load(0x68E25540);
	_soundResource2.load(0x40400457);

	// TODO Sound1ChList_addSoundResource(0x60400854, 0x8101A241, true);
	// TODO Sound1ChList_playLooping(0x8101A241);

}

Scene2202::~Scene2202() {
	// TODO Sound1ChList_sub_407AF0(0x60400854);
}

void Scene2202::update() {
	Scene::update();

	if (_leaveScene && !_soundResource2.isPlaying()) {
		_parentModule->sendMessage(0x1009, 0, this);
	}

	if (_isSolved && !_soundResource1.isPlaying()) {
		_soundResource2.play();
		_isSolved = false;
		_leaveScene = true;
	}

	if (_movingTileSprite && !_isTileMoving) {
		int16 value = getFreeTileIndex(_movingTileIndex);
		if (value != -1) {
			setSurfacePriority(_movingTileSprite->getSurface(), 700);
			_movingTileSprite->sendMessage(0x2001, value, this);
			_movingTileSprite = NULL;
			_isTileMoving = true;
		}
	}

	if (_doneMovingTileSprite) {
		setSurfacePriority(_doneMovingTileSprite->getSurface(), _surfacePriority);
		_doneMovingTileSprite = NULL;
		if (testIsSolved()) {
			_soundResource1.play();
			setGlobalVar(0x404290D5, 1);
			_isSolved = true;
		}
	}
	
}

uint32 Scene2202::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	Scene::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x0001:
		// TODO Debug stuff
		if (param.asPoint().x <= 20 || param.asPoint().x >= 620) {
			_parentModule->sendMessage(0x1009, 0, this);
		}
		break;
	case 0x000D:
		// TODO Debug stuff
		break;
	case 0x2000:
		_movingTileIndex = (int16)param.asInteger();
		_movingTileSprite = (Sprite*)sender;
		break;
	case 0x2002:
		_isTileMoving = false;
		_doneMovingTileSprite = (Sprite*)sender;
		if (param.asInteger() >= 0 && param.asInteger() <= 2) {
			_surfacePriority = 100;
		} else if (param.asInteger() >= 3 && param.asInteger() <= 5) {
			_surfacePriority = 300;
		} else {
			_surfacePriority = 500;
		}
		break;
	}
	return 0;
}

int16 Scene2202::getFreeTileIndex(int16 index) {
	if (index >= 3 && (int16)getSubVar(0x484498D0, index - 3) == -1) {
		return index - 3;
	} else if (index <= 5 && (int16)getSubVar(0x484498D0, index + 3) == -1) {
		return index + 3;
	} else if (index != 0 && index != 3 && index != 6 && (int16)getSubVar(0x484498D0, index - 1) == -1) {
		return index - 1;
	} else if (index != 2 && index != 5 && index != 8 && (int16)getSubVar(0x484498D0, index + 1) == -1) {
		return index + 1;
	} else
		return -1;
}

bool Scene2202::testIsSolved() {
	return 
		getSubVar(0x484498D0, 0) == 0 &&
		getSubVar(0x484498D0, 2) == 2 &&
		getSubVar(0x484498D0, 3) == 3 &&
		getSubVar(0x484498D0, 4) == 4 &&
		getSubVar(0x484498D0, 5) == 5 &&
		getSubVar(0x484498D0, 6) == 6 &&
		getSubVar(0x484498D0, 8) == 7;
}

static const uint32 kClass545FileHashes[] = {
	0x2450D850,
	0x0C9CE8D0,
	0x2C58A152
};

Class545::Class545(NeverhoodEngine *vm, Scene *parentScene, int index, int surfacePriority, int16 x, int16 y)
	: AnimatedSprite(vm, kClass545FileHashes[index], surfacePriority, x, y), _parentScene(parentScene), _index(index) {

	if (!getSubVar(0x0090EA95, _index) && !getSubVar(0x08D0AB11, _index)) {
		SetMessageHandler(&Class545::handleMessage);
	} else {
		_surface->setVisible(false);
		SetMessageHandler(NULL);
	}
}

uint32 Class545::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Sprite::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x1011:
		_parentScene->sendMessage(0x4826, 0, this);
		messageResult = 1;
		break;
	case 0x4806:
		setSubVar(0x0090EA95, _index, 1);
		_surface->setVisible(false);
		SetMessageHandler(NULL);
	}
	return messageResult;
}

static const uint32 kAsScene2203DoorFileHashes[] = {
	0x7868AE10,
	0x1A488110
};

AsScene2203Door::AsScene2203Door(NeverhoodEngine *vm, Scene *parentScene, int index)
	: AnimatedSprite(vm, 1100), _soundResource(vm), _parentScene(parentScene),
	_index(index) {

	SetUpdateHandler(&AnimatedSprite::update);
	SetMessageHandler(&AsScene2203Door::handleMessage);
	_x = 320;
	_y = 240;
	createSurface1(kAsScene2203DoorFileHashes[_index], 900);
	if (getGlobalVar(0x9A500914) == _index) {
		setFileHash(kAsScene2203DoorFileHashes[_index], -1, -1);
		_newHashListIndex = -2;
	} else {
		setFileHash(kAsScene2203DoorFileHashes[_index], 0, -1);
		_newHashListIndex = 0;
	}
}

uint32 AsScene2203Door::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Sprite::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x1011:
		if (_index == getGlobalVar(0x9A500914))
			_parentScene->sendMessage(0x2002, 0, this);
		else
			_parentScene->sendMessage(0x2001, 0, this);
		messageResult = 1;
		break;
	case 0x2000:
		_otherDoor = (Sprite*)param.asEntity();
		break;
	case 0x3002:
		if (_index == getGlobalVar(0x9A500914))
			_parentScene->sendMessage(0x4808, 0, this);
		setFileHash1();
		break;
	case 0x4808:
		setGlobalVar(0x9A500914, _index);
		_otherDoor->sendMessage(0x4809, 0, this);
		openDoor();
		break;
	case 0x4809:
		closeDoor();
		_parentScene->sendMessage(0x2003, 0, this);
		break;
	}
	return messageResult;
}

void AsScene2203Door::openDoor() {
	_soundResource.play(0x341014C4);
	setFileHash(kAsScene2203DoorFileHashes[_index], 1, -1);
}

void AsScene2203Door::closeDoor() {
	setFileHash(kAsScene2203DoorFileHashes[_index], -1, -1);
	_playBackwards = true;
	_newHashListIndex = 0;
}

Scene2203::Scene2203(NeverhoodEngine *vm, Module *parentModule, int which)
	: Scene(vm, parentModule, true) {

	if (getGlobalVar(0xC0780812) && !getGlobalVar(0x13382860))
		setGlobalVar(0x13382860, 1);

	SetMessageHandler(&Scene2203::handleMessage);
	_surfaceFlag = true;

	_background = addBackground(new DirtyBackground(_vm, 0x82C80334, 0, 0));
	_palette = new Palette(_vm, 0x82C80334);
	_palette->usePalette();
	_mouseCursor = addSprite(new Mouse433(_vm, 0x80330824, NULL));

	_vm->_collisionMan->setHitRects(0x004B8320);

	if (getGlobalVar(0x13382860) == 1) {
		_class545 = addSprite(new Class545(_vm, this, 2, 1100, 282, 432));
		_vm->_collisionMan->addSprite(_class545);
	}

	_asTape = addSprite(new AsScene1201Tape(_vm, this, 1, 1100, 435, 432, 0x9148A011));
	_vm->_collisionMan->addSprite(_asTape);

	_asLeftDoor = addSprite(new AsScene2203Door(_vm, this, 0));
	_asRightDoor = addSprite(new AsScene2203Door(_vm, this, 1));
	
	_ssSmallLeftDoor = addSprite(new StaticSprite(_vm, 0x542CC072, 1100));
	_ssSmallRightDoor = addSprite(new StaticSprite(_vm, 0x0A2C0432, 1100));
	
	_leftDoorClipRect.x1 = _ssSmallLeftDoor->getSurface()->getDrawRect().x;
	_leftDoorClipRect.y1 = 0;
	_leftDoorClipRect.x2 = 640;
	_leftDoorClipRect.y2 = 480;
	
	_rightDoorClipRect.x1 = 0;
	_rightDoorClipRect.y1 = 0;
	_rightDoorClipRect.x2 = _ssSmallRightDoor->getSurface()->getDrawRect().x + _ssSmallRightDoor->getSurface()->getDrawRect().width;
	_rightDoorClipRect.y2 = 480;

	_asLeftDoor->sendEntityMessage(0x2000, _asRightDoor, this);
	_asRightDoor->sendEntityMessage(0x2000, _asLeftDoor, this);
	
	_vm->_collisionMan->addSprite(_asLeftDoor);
	_vm->_collisionMan->addSprite(_asRightDoor);

	if (which < 0) {
		_klayman = new KmScene2203(_vm, this, 200, 427);
		setMessageList(0x004B8340);
	} else if (which == 1) {
		_klayman = new KmScene2203(_vm, this, 640, 427);
		setMessageList(0x004B8350);
	} else if (which == 2) {
		if (getGlobalVar(0xC0418A02)) {
			_klayman = new KmScene2203(_vm, this, 362, 427);
			_klayman->setDoDeltaX(1);
		} else {
			_klayman = new KmScene2203(_vm, this, 202, 427);
		}
		setMessageList(0x004B8358);
	} else {
		_klayman = new KmScene2203(_vm, this, 0, 427);
		setMessageList(0x004B8348);
	}
	addSprite(_klayman); 

	if (getGlobalVar(0x9A500914)) {
		_ssSmallLeftDoor->getSurface()->setVisible(false);
		_klayman->getSurface()->getClipRect() = _rightDoorClipRect;
	} else {
		_ssSmallRightDoor->getSurface()->setVisible(false);
		_klayman->getSurface()->getClipRect() = _leftDoorClipRect;
	}
	
	setRectList(0x004B8420);

}

Scene2203::~Scene2203() {
	setGlobalVar(0xC0418A02, _klayman->isDoDeltaX() ? 1 : 0);
}

uint32 Scene2203::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Scene::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x2001:
		_klayman->sendEntityMessage(0x1014, sender, this);
		if (sender == _asLeftDoor) {
			setMessageList2(0x004B83B0);
		} else {
			setMessageList2(0x004B83C8);
		}
		break;
	case 0x2002:
		if (sender == _asLeftDoor) {
			setMessageList2(0x004B8370);
		} else {
			setMessageList2(0x004B8360);
		}
		break;
	case 0x2003:
		if (sender == _asLeftDoor) {
			_ssSmallLeftDoor->getSurface()->setVisible(false);
		} else {
			_ssSmallRightDoor->getSurface()->setVisible(false);
		}
		break;
	case 0x4808:
		if (sender == _asLeftDoor) {
			_ssSmallLeftDoor->getSurface()->setVisible(true);
			_klayman->getSurface()->getClipRect() = _leftDoorClipRect;
		} else {
			_ssSmallRightDoor->getSurface()->setVisible(true);
			_klayman->getSurface()->getClipRect() = _rightDoorClipRect;
		}
		break;
	case 0x4826:
		if (sender == _asTape) {
			_klayman->sendEntityMessage(0x1014, _asTape, this);
			setMessageList(0x004B83E0);
		} else if (sender == _class545) {
			_klayman->sendEntityMessage(0x1014, _class545, this);
			setMessageList(0x004B83F0);
		}
		break;
	}
	return messageResult;
}

SsScene2205DoorFrame::SsScene2205DoorFrame(NeverhoodEngine *vm)
	: StaticSprite(vm, 900) {

	SetMessageHandler(&SsScene2205DoorFrame::handleMessage);
	_spriteResource.load2(getGlobalVar(0x4D080E54) ? 0x24306227 : 0xD90032A0);
	createSurface(1100, 45, 206);
	_drawRect.x = 0;
	_drawRect.y = 0;
	_drawRect.width = _spriteResource.getDimensions().width;
	_drawRect.height = _spriteResource.getDimensions().height;
	_x = _spriteResource.getPosition().x;
	_y = _spriteResource.getPosition().y;
	_needRefresh = true;
	StaticSprite::update();
}

uint32 SsScene2205DoorFrame::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Sprite::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x2000:
		_spriteResource.load2(getGlobalVar(0x4D080E54) ? 0x24306227 : 0xD90032A0);
		_drawRect.x = 0;
		_drawRect.y = 0;
		_drawRect.width = _spriteResource.getDimensions().width;
		_drawRect.height = _spriteResource.getDimensions().height;
		_x = _spriteResource.getPosition().x;
		_y = _spriteResource.getPosition().y;
		_needRefresh = true;
		StaticSprite::update();
	}
	return messageResult;
}

Scene2205::Scene2205(NeverhoodEngine *vm, Module *parentModule, int which)
	: Scene(vm, parentModule, true) {

	Palette2 *palette2;
	
	SetMessageHandler(&Scene2205::handleMessage);
	SetUpdateHandler(&Scene2205::update);
	
	_vm->_collisionMan->setHitRects(0x004B0620);
	_surfaceFlag = true;

	if (getGlobalVar(0x4D080E54)) {
		_isLightOn = true;
		_background = addBackground(new DirtyBackground(_vm, 0x0008028D, 0, 0));
		palette2 = new Palette2(_vm, 0x0008028D);
		_palette = palette2;
		_palette->usePalette();
		addEntity(palette2);
		_mouseCursor = addSprite(new Mouse433(_vm, 0x80289008, NULL));
		_ssLightSwitch = new Class426(_vm, this, 0x2D339030, 0x2D309030, 100, 0);
		addSprite(_ssLightSwitch);
	} else {
		_isLightOn = false;
		_background = addBackground(new DirtyBackground(_vm, 0xD00A028D, 0, 0));
		palette2 = new Palette2(_vm, 0xD00A028D);
		_palette = palette2;
		_palette->usePalette();
		addEntity(palette2);
		_mouseCursor = addSprite(new Mouse433(_vm, 0xA0289D08, NULL));
		_ssLightSwitch = new Class426(_vm, this, 0x2D339030, 0xDAC86E84, 100, 0);
		addSprite(_ssLightSwitch);
	}

	palette2->addPalette(0xD00A028D, 0, 256, 0);
	
	_ssDoorFrame = addSprite(new SsScene2205DoorFrame(_vm));

	if (which < 0) {
		_klayman = new KmScene2205(_vm, this, 320, 417);
		setMessageList(0x004B0658);
		if (!getGlobalVar(0x4D080E54)) {
			_palette->addPalette(0x68033B1C, 0, 65, 0);
		}
		_isKlaymanInLight = false;
	} else if (which == 1) {
		_klayman = new KmScene2205(_vm, this, 640, 417);
		setMessageList(0x004B0648);
		if (!getGlobalVar(0x4D080E54)) {
			_palette->addPalette(0x68033B1C, 0, 65, 0);
		}
		_isKlaymanInLight = false;
	} else {
		_klayman = new KmScene2205(_vm, this, 0, 417);
		setMessageList(0x004B0640);
		_isKlaymanInLight = true;
	}
	addSprite(_klayman);

	_klayman->getSurface()->getClipRect().x1 = _ssDoorFrame->getSurface()->getDrawRect().x;
	_klayman->getSurface()->getClipRect().y1 = 0;
	_klayman->getSurface()->getClipRect().x2 = 640;
	_klayman->getSurface()->getClipRect().y2 = 480;

	loadDataResource(0x00144822);
	_klayman->setSoundFlag(true);

}
	
void Scene2205::update() {
	Scene::update();

	if (!_isLightOn && getGlobalVar(0x4D080E54)) {
		_palette->addPalette(0x0008028D, 0, 256, 0);
		_background->load(0x0008028D);
		_ssLightSwitch->setFileHashes(0x2D339030, 0x2D309030);
		_ssDoorFrame->sendMessage(0x2000, 0, this);
		((Mouse433*)_mouseCursor)->load(0x80289008);
		((Mouse433*)_mouseCursor)->updateCursor();
		_isLightOn = true;
	} else if (_isLightOn && !getGlobalVar(0x4D080E54)) {
		_palette->addPalette(0xD00A028D, 0, 256, 0);
		_background->load(0xD00A028D);
		_ssLightSwitch->setFileHashes(0x2D339030, 0xDAC86E84);
		_ssDoorFrame->sendMessage(0x2000, 0, this);
		((Mouse433*)_mouseCursor)->load(0xA0289D08);
		((Mouse433*)_mouseCursor)->updateCursor();
		_isKlaymanInLight = true;
		if (_klayman->getX() > 85) {
			_palette->addPalette(0x68033B1C, 0, 65, 0);
			_isKlaymanInLight = false;
		}
		_isLightOn = false;
	}

	if (!getGlobalVar(0x4D080E54)) {
		if (_isKlaymanInLight && _klayman->getX() > 85) {
			((Palette2*)_palette)->addPalette(0x68033B1C, 0, 65, 0);
			((Palette2*)_palette)->startFadeToPalette(12);
			_isKlaymanInLight = false;
		} else if (!_isKlaymanInLight && _klayman->getX() <= 85) {
			((Palette2*)_palette)->addPalette(0xD00A028D, 0, 65, 0);
			((Palette2*)_palette)->startFadeToPalette(12);
			_isKlaymanInLight = true;
		}
	}
	
}

uint32 Scene2205::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	Scene::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x100D:
		if (param.asInteger() == 0x6449569A) {
			setMessageList(0x004B0690);
		} else if (param.asInteger() == 0x2841369C) {
			setMessageList(0x004B0630);
		} else if (param.asInteger() == 0x402064D8) {
			_klayman->sendEntityMessage(0x1014, _ssLightSwitch, this);
		}
		break;
	case 0x480B:
		setGlobalVar(0x4D080E54, getGlobalVar(0x4D080E54) ? 0 : 1);
		break;
	}
	return 0;
}

static const int16 kScene2206XPositions[] = {
	384, 
	480, 
	572
};

static const uint32 kScene2206MessageIds1[] = {
	0x004B8998,
	0x004B89B8,
	0x004B89D8
};

static const uint32 kScene2206MessageIds2[] = {
	0x004B89F8,
	0x004B8A20,
	0x004B8A48
};

static const int16 kClass603XDeltas1[] = {
	-24, -28, -18, 6, 9, -8
};

static const int16 kClass603XDeltas2[] = {
	-8, 7, 11, 26, 13, 14
};

Class603::Class603(NeverhoodEngine *vm, uint32 fileHash)
	: StaticSprite(vm, fileHash, 200), _soundResource(vm) {
	
	if (getGlobalVar(0x18890C91))
		_x -= 63;
	SetUpdateHandler(&Class603::update);
	SetMessageHandler(&Class603::handleMessage);
	SetSpriteCallback(NULL);
}

void Class603::update() {
	handleSpriteUpdate();
	StaticSprite::update();
}

uint32 Class603::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Sprite::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x4808:
		_index = 0;
		SetMessageHandler(NULL);
		SetSpriteCallback(&Class603::spriteUpdate481E60);
		_soundResource.play(0x032746E0);
		break;
	case 0x4809:
		_index = 0;
		SetMessageHandler(NULL);
		SetSpriteCallback(&Class603::spriteUpdate481E90);
		_soundResource.play(0x002642C0);
		break;
	}
	return messageResult;
}

void Class603::spriteUpdate481E60() {
	if (_index < 6) {
		_x += kClass603XDeltas1[_index];
		_index++;
	} else {
		SetMessageHandler(&Class603::handleMessage);
		SetSpriteCallback(NULL);
	}
}

void Class603::spriteUpdate481E90() {
	if (_index < 6) {
		_x += kClass603XDeltas2[_index];
		_index++;
	} else {
		SetMessageHandler(&Class603::handleMessage);
		SetSpriteCallback(NULL);
	}
}

Class604::Class604(NeverhoodEngine *vm, uint32 fileHash)
	: StaticSprite(vm, fileHash, 50) {

	SetUpdateHandler(&Class604::update);
	SetMessageHandler(&Class604::handleMessage);
	SetSpriteCallback(NULL);
}

void Class604::update() {
	handleSpriteUpdate();
	StaticSprite::update();
}

uint32 Class604::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Sprite::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x4803:
		SetMessageHandler(NULL);
		SetSpriteCallback(&Class604::spriteUpdate482020);
		_yDelta = 0;
		break;
	}
	return messageResult;
}

void Class604::spriteUpdate482020() {
	_yDelta++;
	_y += _yDelta;
}

Class607::Class607(NeverhoodEngine *vm, Scene *parentScene, int surfacePriority, uint32 fileHash)
	: StaticSprite(vm, fileHash, surfacePriority), _parentScene(parentScene) {

	if (getGlobalVar(0x45080C38)) {
		_surface->setVisible(false);
		SetMessageHandler(NULL);
	} else {
		SetMessageHandler(&Class607::handleMessage);
	}
	_deltaRect = _drawRect;
	processDelta();
}

uint32 Class607::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Sprite::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x1011:
		_parentScene->sendMessage(0x4826, 0, this);
		messageResult = 1;
		break;
	case 0x4806:
		setGlobalVar(0x45080C38, 1);
		_surface->setVisible(false);
		SetMessageHandler(NULL);
		break;
	}
	return messageResult;
}

Scene2206::Scene2206(NeverhoodEngine *vm, Module *parentModule, int which)
	: Scene(vm, parentModule, true), _soundResource(vm) {

	uint32 fileHash;
	Palette2 *palette2;
	
	SetUpdateHandler(&Scene::update);
	SetMessageHandler(&Scene2206::handleMessage);
	_surfaceFlag = true;
	
	if (getGlobalVar(0x4D080E54)) {
		fileHash = 0x41983216;
		_sprite1 = addSprite(new StaticSprite(_vm, 0x2201266A, 100));
		_sprite2 = addSprite(new StaticSprite(_vm, 0x3406A333, 300));
		_sprite3 = addSprite(new StaticSprite(_vm, 0x24A223A2, 100));
		_sprite4 = addSprite(new Class603(_vm, 0x26133023));
		_sprite4->getSurface()->getClipRect().x1 = _sprite2->getSurface()->getDrawRect().x;
		_sprite4->getSurface()->getClipRect().y1 = 0;
		_sprite4->getSurface()->getClipRect().x2 = 640;
		_sprite4->getSurface()->getClipRect().y2 = 480;
		setRectList(0x004B8AF8);
		_sprite5 = addSprite(new SsCommonButtonSprite(_vm, this, 0x0E038022, 100, 0));
		_mouseCursor = addSprite(new Mouse433(_vm, 0x83212411, NULL));
		_class607 = addSprite(new Class607(_vm, this, 1100, /*464, 433, */0x5E00E262));
		_class604 = addSprite(new Class604(_vm, 0x085E25E0));
	} else {
		fileHash = 0xE0102A45;
		_sprite1 = addSprite(new StaticSprite(_vm, 0x1C1106B8, 100));
		_sprite2 = addSprite(new StaticSprite(_vm, 0x020462E0, 300));
		_sprite3 = addSprite(new StaticSprite(_vm, 0x900626A2, 100));
		_sprite4 = addSprite(new Class603(_vm, 0x544822A8));
		_sprite4->getSurface()->getClipRect().x1 = _sprite2->getSurface()->getDrawRect().x;
		_sprite4->getSurface()->getClipRect().y1 = 0;
		_sprite4->getSurface()->getClipRect().x2 = 640;
		_sprite4->getSurface()->getClipRect().y2 = 480;
		setRectList(0x004B8B58);
		_sprite5 = addSprite(new SsCommonButtonSprite(_vm, this, 0x16882608, 100, 0));
		_mouseCursor = addSprite(new Mouse433(_vm, 0x02A41E09, NULL));
		_class607 = addSprite(new Class607(_vm, this, 1100, /*464, 433, */0x52032563));
		_class604 = addSprite(new Class604(_vm, 0x317831A0));
	}

	_class604->getSurface()->getClipRect().x1 = _sprite2->getSurface()->getDrawRect().x;
	_class604->getSurface()->getClipRect().y1 = 0;
	_class604->getSurface()->getClipRect().x2 = _sprite3->getSurface()->getDrawRect().x + _sprite3->getSurface()->getDrawRect().width;
	_class604->getSurface()->getClipRect().y2 = _sprite1->getSurface()->getDrawRect().y + _sprite1->getSurface()->getDrawRect().height;

	_background = addBackground(new DirtyBackground(_vm, fileHash, 0, 0));

	palette2 = new Palette2(_vm, fileHash);
	_palette = palette2;
	_palette->usePalette();
	addEntity(palette2);

	palette2->addPalette(fileHash, 0, 256, 0);

	if (!getGlobalVar(0x4D080E54)) {
		_palette->addPalette(0x0263D144, 0, 65, 0);
	}
	
	_vm->_collisionMan->addSprite(_class607);
	
	if (which < 0) {
		_klayman = new KmScene2206(_vm, this, 200, 430);
		setMessageList(0x004B88A8);
	} else if (which == 1) {
		_klayman = new KmScene2206(_vm, this, 640, 430);
		setMessageList(0x004B88B8);
	} else if (which == 2) {
		_klayman = new KmScene2206(_vm, this, 205, 396);
		setMessageList(0x004B88C8);
		_palette->addPalette(getGlobalVar(0x4D080E54) ? 0xB103B604 : 0x0263D144, 0, 65, 0);
		sub4819D0();
		_soundResource.play(0x53B8284A);
	} else if (which == 3) {
		_klayman = new KmScene2206(_vm, this, kScene2206XPositions[getGlobalVar(0x48A68852)], 430);
		if (getGlobalVar(0xC0418A02))
			_klayman->setDoDeltaX(1);
		setMessageList(0x004B8A70);
	} else {
		_klayman = new KmScene2206(_vm, this, 0, 430);
		setMessageList(0x004B88B0);
	}
	addSprite(_klayman);

	_klayman->setSoundFlag(true);
	_klayman->setKlaymanTable2();

}

Scene2206::~Scene2206() {
	setGlobalVar(0xC0418A02, _klayman->isDoDeltaX() ? 1 : 0);
}

uint32 Scene2206::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Scene::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x100D:
		if (param.asInteger() == 0x800C6694) {
			sub481B00();
		} else if (param.asInteger() == 0x402064D8) {
			_klayman->sendEntityMessage(0x1014, _sprite5, this);
		} else if (param.asInteger() == 0x11C40840) {
			if (getGlobalVar(0x18890C91))
				setMessageList(0x004B8948);
			else
				setMessageList(0x004B8970);
		}
		break;
	case 0x4803:
		_class604->sendMessage(0x4803, 0, this);
		break;
	case 0x480B:
		if (sender == _sprite5) {
			setGlobalVar(0x18890C91, getGlobalVar(0x18890C91) ? 0 : 1);
			if (getGlobalVar(0x18890C91))
				_sprite4->sendMessage(0x4808, 0, this);
			else
				_sprite4->sendMessage(0x4809, 0, this);
		}
		break;
	case 0x4826:
		_klayman->sendEntityMessage(0x1014, _class607, this);
		setMessageList(0x004B8988);
		break;
	case 0x482A:
		sub4819D0();
		break;
	case 0x482B:
		sub481950();
		break;
	}
	return messageResult;
}

void Scene2206::sub481950() {
	if (getGlobalVar(0x4D080E54)) {
		((Palette2*)_palette)->addPalette(0x41983216, 0, 65, 0);
		((Palette2*)_palette)->startFadeToPalette(12);
	}
	setSurfacePriority(_sprite1->getSurface(), 100);
	setSurfacePriority(_sprite2->getSurface(), 300);
	setSurfacePriority(_sprite3->getSurface(), 100);
	setSurfacePriority(_sprite4->getSurface(), 200);
	_klayman->getSurface()->getClipRect().x1 = 0;
	_klayman->getSurface()->getClipRect().y1 = 0;
	_klayman->getSurface()->getClipRect().x2 = 640;
	_klayman->getSurface()->getClipRect().y2 = 480;
}

void Scene2206::sub4819D0() {
	if (!getGlobalVar(0x4D080E54)) {
		((Palette2*)_palette)->addPalette(0xB103B604, 0, 65, 0);
		((Palette2*)_palette)->startFadeToPalette(12);
	}
	setSurfacePriority(_sprite1->getSurface(), 1100);
	setSurfacePriority(_sprite2->getSurface(), 1300);
	setSurfacePriority(_sprite3->getSurface(), 1100);
	setSurfacePriority(_sprite4->getSurface(), 1200);
	_klayman->getSurface()->getClipRect().x1 = _sprite2->getSurface()->getDrawRect().x;
	_klayman->getSurface()->getClipRect().y1 = 0;
	_klayman->getSurface()->getClipRect().x2 = _sprite3->getSurface()->getDrawRect().x + _sprite3->getSurface()->getDrawRect().width;
	_klayman->getSurface()->getClipRect().y2 = _sprite1->getSurface()->getDrawRect().y + _sprite1->getSurface()->getDrawRect().height;
}

void Scene2206::sub481B00() {
	setGlobalVar(0x48A68852, (_mouseClickPos.x - 354) / 96);
	if (getGlobalVar(0x48A68852) > 2)
		setGlobalVar(0x48A68852, 2);
	setGlobalVar(0x49C40058, (_mouseClickPos.y - 183) / 7);
	setGlobalVar(0xC8C28808, calcHash("stLineagex"));
	setGlobalVar(0x4CE79018, 0);
	if (ABS(kScene2206XPositions[getGlobalVar(0x48A68852)] - _klayman->getX()) >= 144) {
		setMessageList2(kScene2206MessageIds1[getGlobalVar(0x48A68852)]);
	} else {
		setMessageList2(kScene2206MessageIds2[getGlobalVar(0x48A68852)]);
	}
}

static const uint32 kScene2207FileHashes[] = {
	0x33B1E12E,
	0x33D1E12E,
	0x3311E12E,
	0x3291E12E,
	0x3191E12E,
	0x3791E12E,
	0x3B91E12E,
	0x2391E12E,
	0x1391E12E,
	0x3BB1E12E,
	0x23B1E12E,
	0x13B1E12E
};

AsScene2207Elevator::AsScene2207Elevator(NeverhoodEngine *vm, Scene *parentScene)
	: AnimatedSprite(vm, 900), _parentScene(parentScene), _soundResource(vm),
	_pointIndex(0), _destPointIndex(0), _destPointIndexDelta(0) {

	NPoint pt;

	_dataResource.load(0x00524846);
	_pointArray = _dataResource.getPointArray(0x005B02B7);
	pt = _dataResource.getPoint(0x403A82B1);
	_x = pt.x;
	_y = pt.y;
	createSurface(1100, 129, 103);
	setFileHash(getGlobalVar(0x4D080E54) ? 0xC858CC19 : 0x294B3377, 0, 0);
	SetUpdateHandler(&AsScene2207Elevator::update);
	SetSpriteCallback(&AsScene2207Elevator::suSetPosition);
	SetMessageHandler(&AsScene2207Elevator::handleMessage);
	_newHashListIndex = 0;
}

AsScene2207Elevator::~AsScene2207Elevator() {
	// TODO Sound1ChList_sub_407AF0(0x02700413);
}

void AsScene2207Elevator::update() {

	if (_destPointIndex + _destPointIndexDelta > _pointIndex) {
		_pointIndex++;
		setFileHash(getGlobalVar(0x4D080E54) ? 0xC858CC19 : 0x294B3377, _pointIndex, _pointIndex);
		_newHashListIndex = _pointIndex;		
		if (_destPointIndex + _destPointIndexDelta == _pointIndex) {
			if (_destPointIndexDelta != 0) {
				_destPointIndexDelta = 0;
			} else {
				// TODO Sound1ChList_deleteSoundByHash(0xD3B02847);
				_soundResource.play(0x53B8284A);
			}
		}
	}

	if (_destPointIndex + _destPointIndexDelta < _pointIndex) {
		_pointIndex--;
		if (_pointIndex == 0)
			_parentScene->sendMessage(0x2003, 0, this);
		setFileHash(getGlobalVar(0x4D080E54) ? 0xC858CC19 : 0x294B3377, _pointIndex, _pointIndex);
		_newHashListIndex = _pointIndex;		
		if (_destPointIndex + _destPointIndexDelta == _pointIndex) {
			if (_destPointIndexDelta != 0) {
				_destPointIndexDelta = 0;
			} else {
				// TODO Sound1ChList_deleteSoundByHash(0xD3B02847);
				_soundResource.play(0x53B8284A);
			}
		}
	}

	if (_pointIndex > 20 && _surface->getPriority() != 900) {
		_parentScene->sendMessage(0x2002, 900, this);
	} else if (_pointIndex < 20 && _surface->getPriority() != 1100) {
		_parentScene->sendMessage(0x2002, 1100, this);
	}
	
	AnimatedSprite::update();
	
	if (_destPointIndex + _destPointIndexDelta == _pointIndex && _isMoving) {
		_parentScene->sendMessage(0x2004, 0, this);
		_isMoving = false;
	}
	
}

void AsScene2207Elevator::suSetPosition() {
	_x = (*_pointArray)[_pointIndex].x;
	_y = (*_pointArray)[_pointIndex].y - 60;
	processDelta();
}

uint32 AsScene2207Elevator::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Sprite::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x2000:
		moveToY(param.asInteger());
		break;
	}
	return messageResult;
}

void AsScene2207Elevator::moveToY(int16 y) {
	int16 minDistance = 480;

	if (!_pointArray || _pointArray->size() == 0)
		return;
	
	for (uint i = 0; i < _pointArray->size(); i++) {
		int16 distance = ABS(y - (*_pointArray)[i].y);
		if (distance < minDistance) {
			minDistance = distance;
			_destPointIndex = i;
		}
	}	

	if (_destPointIndex != _pointIndex) {
		if (_destPointIndex == 0 || _destPointIndex == _pointArray->size() - 1) {
			_destPointIndexDelta = 0;
		} else if (_destPointIndex < _pointIndex) {
			_destPointIndexDelta = -2;
		} else {
			_destPointIndexDelta = 2;
		}
		// TODO Sound1ChList_addSoundResource(0x02700413, 0xD3B02847, true);
		// TODO Sound1ChList_playLooping(0xD3B02847);
	}

	_isMoving = true;

}

Class500::Class500(NeverhoodEngine *vm, Scene *parentScene)
	: AnimatedSprite(vm, 1200), _soundResource1(vm), _soundResource2(vm),
	_soundResource3(vm), _soundResource4(vm), _flag1(true) {
	
	SetUpdateHandler(&AnimatedSprite::update);
	SetMessageHandler(&Class500::handleMessage);
	createSurface1(0xCCFD6090, 100);
	_x = 309;
	_y = 320;
	setFileHash(0xCCFD6090, 0, -1);
	_newHashListIndex = 0;
	_soundResource2.load(0x40330872);
	_soundResource3.load(0x72A2914A);
	_soundResource4.load(0xD4226080);
}

Class500::~Class500() {
	// TODO Sound1ChList_sub_407AF0(0x80D00820);
}

uint32 Class500::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Sprite::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x100D:
		if (!_flag1) {
			if (param.asInteger() == 0x3423093) {
				// TODO Sound1ChList_addSoundResource(0x80D00820, 0x12121943, true);
				// TODO Sound1ChList_playLooping(0x12121943);
			} else if (param.asInteger() == 0x834AB011) {
				_soundResource1.stop();
				_soundResource2.stop();
				_soundResource3.stop();
				_soundResource4.stop();
				// TODO Sound1ChList_deleteSoundByHash(0x12121943);
			} else if (param.asInteger() == 0x3A980501) {
				_soundResource2.play();
			} else if (param.asInteger() == 0x2A2AD498) {
				_soundResource3.play();
			} else if (param.asInteger() == 0xC4980008) {
				_soundResource4.play();
			} else if (param.asInteger() == 0x06B84228) {
				_soundResource1.play(0xE0702146);
			}
		}
		break;
	case 0x2006:
		sub441D50();
		break;
	case 0x2007:
		sub441D90();
		break;
	case 0x3002:
		removeCallbacks();
		break;
	}
	return messageResult;
}

void Class500::sub441D50() {
	if (!_flag1) {
		SetAnimationCallback3(NULL);
	} else {
		setFileHash(0xCCFD6090, 0, -1);
		_flag1 = false;
		_surface->setVisible(true);
	}
}

void Class500::sub441D90() {
	SetAnimationCallback3(&Class500::sub441DA0);
}

void Class500::sub441DA0() {
	setFileHash1();
	_soundResource1.stop();
	_soundResource2.stop();
	_soundResource3.stop();
	_soundResource4.stop();
	// TODO Sound1ChList_deleteSoundByHash(0x12121943);
	_flag1 = true;
	_surface->setVisible(false);
}

Class501::Class501(NeverhoodEngine *vm)
	: AnimatedSprite(vm, 1200), _flag1(true) {
	
	SetUpdateHandler(&AnimatedSprite::update);
	SetMessageHandler(&Class501::handleMessage);
	createSurface1(0x8CAA0099, 100);
	_x = 309;
	_y = 320;
	setFileHash(0x8CAA0099, 0, -1);
	_newHashListIndex = 0;
}

uint32 Class501::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Sprite::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x2006:
		sub441FA0();
		break;
	case 0x2007:
		sub441FE0();
		break;
	case 0x3002:
		removeCallbacks();
		break;
	}
	return messageResult;
}

void Class501::sub441FA0() {
	if (!_flag1) {
		SetAnimationCallback3(NULL);
	} else {
		_surface->setVisible(true);
		setFileHash(0x8CAA0099, 0, -1);
		_flag1 = false;
	}
}

void Class501::sub441FE0() {
	SetAnimationCallback3(&Class501::sub441FF0);
}

void Class501::sub441FF0() {
	setFileHash1();
	_surface->setVisible(false);
	_flag1 = true;
}

Class597::Class597(NeverhoodEngine *vm, uint32 fileHash, int index)
	: StaticSprite(vm, fileHash, 100) {

	_x = 330;
	_y = 246 + index * 50;
	StaticSprite::update();	
}

Scene2207::Scene2207(NeverhoodEngine *vm, Module *parentModule, int which)
	: Scene(vm, parentModule, true), _soundResource1(vm), _soundResource2(vm),
	_flag1(true), _elevatorSurfacePriority(0) {

	_vm->gameModule()->initScene3009Vars();

	//DEBUG
	setGlobalVar(0x4D080E54, 1);

	if (!getSubVar(0x40050052, 0x88460852))
		setSubVar(0x40050052, 0x88460852, 1);

	SetMessageHandler(&Scene2207::handleMessage);
	SetUpdateHandler(&Scene2207::update);
	_surfaceFlag = true;

	_klayman = new KmScene2207(_vm, this, 0, 0); // CHECKME: Stack vars are uninitialized?!
	addSprite(_klayman);
	_klayman->setRepl(64, 0);
	
	setMessageList(0x004B38E8);
	
	_asElevator = addSprite(new AsScene2207Elevator(_vm, this));
	
	if (getGlobalVar(0x4D080E54)) {

		_background = addBackground(new DirtyBackground(_vm, 0x88C00241, 0, 0));
		_palette = new Palette(_vm, 0x88C00241);
		_palette->usePalette();
		_mouseCursor = addSprite(new Mouse433(_vm, 0x00245884, NULL));
	
		_ssMaskPart1 = addSprite(new StaticSprite(_vm, 0xE20A28A0, 1200));
		_ssMaskPart2 = addSprite(new StaticSprite(_vm, 0x688F62A5, 1100));
		_ssMaskPart3 = addSprite(new StaticSprite(_vm, 0x0043B038, 1100));
	
		_asTape = addSprite(new AsScene1201Tape(_vm, this, 4, 1100, 277, 428, 0x9148A011));
		_vm->_collisionMan->addSprite(_asTape); 
	
//		_class487 = addSprite(new Class487(_vm, this, 527, 333, 0));
//		_vm->_collisionMan->addSprite(_class487);
		
		_class500 = addSprite(new Class500(_vm, this));
		_class501 = addSprite(new Class501(_vm));
		
		_class500->getSurface()->setVisible(false);
		_class501->getSurface()->setVisible(false);

		_ssButton = addSprite(new SsCommonButtonSprite(_vm, this, 0x2C4061C4, 100, 0));
	
//		_class487->getSurface()->getClipRect().x1 = 0;
//		_class487->getSurface()->getClipRect().y1 = 0;
//		_class487->getSurface()->getClipRect().x2 = _ssMaskPart3->getSurface()->getDrawRect().x + _ssMaskPart3->getSurface()->getDrawRect().width;
//		_class487->getSurface()->getClipRect().y2 = 480;
	
		_klayman->getSurface()->getClipRect().x1 = 0;
		_klayman->getSurface()->getClipRect().y1 = _ssMaskPart1->getSurface()->getDrawRect().y;
		_klayman->getSurface()->getClipRect().x2 = 640;
		_klayman->getSurface()->getClipRect().y2 = _ssMaskPart2->getSurface()->getDrawRect().y + _ssMaskPart2->getSurface()->getDrawRect().height;
	
		_asElevator->getSurface()->getClipRect().x1 = 0;
		_asElevator->getSurface()->getClipRect().y1 = _ssMaskPart1->getSurface()->getDrawRect().y;
		_asElevator->getSurface()->getClipRect().x2 = 640;
		_asElevator->getSurface()->getClipRect().y2 = _ssMaskPart2->getSurface()->getDrawRect().y + _ssMaskPart2->getSurface()->getDrawRect().height;
	
	} else {

		setGlobalVar(0x81890D14, 1);

		_background = addBackground(new DirtyBackground(_vm, 0x05C02A55, 0, 0));
		_palette = new Palette(_vm, 0x05C02A55);
		_palette->usePalette();
		_mouseCursor = addSprite(new Mouse433(_vm, 0x02A51054, NULL));

		_ssMaskPart1 = addSprite(new StaticSprite(_vm, 0x980E46A4, 1200));

		addSprite(new Class597(_vm, kScene2207FileHashes[getSubVar(0x00504B86, 0)], 0));
		addSprite(new Class597(_vm, kScene2207FileHashes[getSubVar(0x00504B86, 1)], 1));
		addSprite(new Class597(_vm, kScene2207FileHashes[getSubVar(0x00504B86, 2)], 2));

		_asTape = NULL;
		_class487 = NULL;
		_class500 = NULL;
		_class501 = NULL;
		_ssButton = NULL;

		_klayman->getSurface()->getClipRect().x1 = 0;
		_klayman->getSurface()->getClipRect().y1 = _ssMaskPart1->getSurface()->getDrawRect().y;
		_klayman->getSurface()->getClipRect().x2 = 640;
		_klayman->getSurface()->getClipRect().y2 = 480;
		
		_asElevator->getSurface()->getClipRect().x1 = 0;
		_asElevator->getSurface()->getClipRect().y1 = _ssMaskPart1->getSurface()->getDrawRect().y;
		_asElevator->getSurface()->getClipRect().x2 = 640;
		_asElevator->getSurface()->getClipRect().y2 = 480;

	}

	_dataResource.load(0x00524846);

	setRectList(0x004B38B8);

	_klayman->sendEntityMessage(0x1014, _asElevator, this);
	_klayman->sendMessage(0x2001, 0, this);
	_asElevator->sendMessage(0x2000, 480, this);

	_soundResource2.load(calcHash("fxFogHornSoft"));

}

void Scene2207::update() {
	Scene::update();
	if (_elevatorSurfacePriority != 0) {
		setSurfacePriority(_asElevator->getSurface(), _elevatorSurfacePriority);
		_elevatorSurfacePriority = 0;
	}
	if (_klayman->getY() == 423) {
		_flag1 = _klayman->getX() > 459 && _klayman->getX() < 525;
	}
}

uint32 Scene2207::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Scene::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x100D:
		if (param.asInteger() == 0x0014F275) {
			if (_flag1) {
				_asElevator->sendMessage(0x2000, _mouseClickPos.y, this);
				_klayman->sendEntityMessage(0x1014, _asElevator, this);
				_klayman->sendMessage(0x2001, 0, this);
			} else {
				messageList402220();
			}
		} else if (param.asInteger() == 0x34569073) {
			if (_flag1) {
				_messageListFlag1 = true;
				_asElevator->sendMessage(0x2000, 0, this);
				_klayman->sendEntityMessage(0x1014, _asElevator, this);
				_klayman->sendMessage(0x2001, 0, this);
			} else {
				messageList402220();
			}
		} else if (param.asInteger() == 0x4054C877) {
			if (_flag1) {
				_asElevator->sendMessage(0x2000, 480, this);
				_klayman->sendEntityMessage(0x1014, _asElevator, this);
				_klayman->sendMessage(0x2001, 0, this);
			} else {
				messageList402220();
			}
		} else if (param.asInteger() == 0x0CBC6211) {
			_klayman->sendEntityMessage(0x1014, _asElevator, this);
			_klayman->sendMessage(0x2001, 0, this);
			setRectList(0x004B38B8);
		} else if (param.asInteger() == 0x402064D8) {
			_klayman->sendEntityMessage(0x1014, _ssButton, this);
		} else if (param.asInteger() == 0x231DA241) {
			if (_ssButton) {
				setMessageList(0x004B38F0);
			} else {
				setMessageList(0x004B37D8);
			}
		}
		break;
	case 0x2002:
		_elevatorSurfacePriority = param.asInteger();
		break;
	case 0x2003:
		_messageListFlag1 = false;
		break;
	case 0x4807:
		_class500->sendMessage(0x2007, 0, this);
		_class501->sendMessage(0x2007, 0, this);
		break;
	case 0x480B:
		if (sender == _ssButton) {
			if (getSubVar(0x14800353, 0x40119852)) {
				setSubVar(0x14800353, 0x40119852, 0);
				_soundResource1.play(calcHash("fx3LocksDisable"));
			} else {
				setSubVar(0x14800353, 0x40119852, 1);
				_soundResource2.play();
			}
		}
		break;
	case 0x480F:
		_class500->sendMessage(0x2006, 0, this);
		_class501->sendMessage(0x2006, 0, this);
		_class500->getSurface()->setVisible(true);
		_class501->getSurface()->setVisible(true);
		break;
	case 0x4826:
		if (sender == _asTape) {
			if (_klayman->getY() == 423) {
				_klayman->sendEntityMessage(0x1014, _asTape, this);
				setMessageList(0x004B3958);
			}
		} else if (_flag1) {
			SetMessageHandler(&Scene2207::handleMessage2);
			_asElevator->sendMessage(0x2000, 347, this);
			_klayman->sendEntityMessage(0x1014, _asElevator, this);
			_klayman->sendMessage(0x2001, 0, this);
		}
		break;
	}
	return messageResult;
}

uint32 Scene2207::handleMessage2(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Scene::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x2002:
		_elevatorSurfacePriority = param.asInteger();
		break;
	case 0x2004:
		SetMessageHandler(&Scene2207::handleMessage);
		_klayman->sendMessage(0x2005, 0, this);
//		_klayman->sendEntityMessage(0x1014, _class487, this);
		setMessageList(0x004B3920);
		setRectList(0x004B3948);
		break;
	}
	return messageResult;
}

static const uint32 kScene2208FileHashes1[] = {
	0x041023CB,
	0x041020CB,
	0x041026CB,
	0x04102ACB,
	0x041032CB,
	0x041002CB
};
	
static const uint32 kScene2208FileHashes2[] = {
	0x091206C9,
	0x091406C9,
	0x091806C9,
	0x090006C9,
	0x093006C9,
	0x095006C9
};

Scene2208::Scene2208(NeverhoodEngine *vm, Module *parentModule, int which)
	: Scene(vm, parentModule, true), _textResource(vm) {

	SpriteResource spriteResource(_vm);
	const char *textStart, *textEnd;

	if (!getGlobalVar(0xC8C28808))
		setGlobalVar(0xC8C28808, calcHash("stLineagex"));

	_textResource.load(getGlobalVar(0xC8C28808));
	
	textStart = _textResource.getString(getGlobalVar(0x48A68852), textEnd);
	while (textStart < textEnd) {
		_strings.push_back(textStart);
		textStart += strlen(textStart) + 1;
	}
	
	_maxRowIndex = 8 + 10 * (3 - (getGlobalVar(0xC8C28808) == calcHash("stLineagex") ? 1 : 0));

	_background = new Background(_vm, 0);
	_background->createSurface(0, 640, 528);
	_background->getSpriteResource().getPosition().y = 480;
	addBackground(_background);
	
	_palette = new Palette(_vm, 0x08100289);
	_palette->usePalette();
	addEntity(_palette); // Why?

	_mouseCursor = addSprite(new Mouse435(_vm, 0x0028D089, 40, 600));
	
	createFontSurface();
	
	_backgroundSurface = new BaseSurface(_vm, 0, 640, 480);
	spriteResource.load2(0x08100289);
	_backgroundSurface->drawSpriteResourceEx(spriteResource, false, false, 0, 0);

	_topBackgroundSurface = new BaseSurface(_vm, 0, 640, 192);
	spriteResource.load2(!getGlobalVar(0x4CE79018) ? kScene2208FileHashes1[getGlobalVar(0x48A68852) % 6] : getGlobalVar(0x4CE79018));
	_topBackgroundSurface->drawSpriteResourceEx(spriteResource, false, false, 0, 0);

	_bottomBackgroundSurface = new BaseSurface(_vm, 0, 640, 192);
	spriteResource.load2(kScene2208FileHashes2[getGlobalVar(0x48A68852) % 6]);
	_bottomBackgroundSurface->drawSpriteResourceEx(spriteResource, false, false, 0, 0);
	
	SetUpdateHandler(&Scene2208::update);
	SetMessageHandler(&Scene2208::handleMessage);

	_visibleRowsCount = 10;

	_newRowIndex = (int16)getGlobalVar(0x49C40058);
	if (_newRowIndex + _visibleRowsCount > _maxRowIndex)
		_newRowIndex = _maxRowIndex - _visibleRowsCount;
	if (_newRowIndex < 6)
		_newRowIndex = 0;

	_rowScrollY = 0;

	_backgroundScrollY = 48 * _newRowIndex;		

	_currRowIndex = _newRowIndex;

	for (int16 rowIndex = 0; rowIndex < _visibleRowsCount; rowIndex++)
		drawRow(_newRowIndex + rowIndex);

	_background->getSurface()->getSysRect().y = _backgroundScrollY;

	// TODO Screen.yOffset = _backgroundScrollY;
	// TODO Scene2208_sub409080 (creates background Sprites via the text, doesn't seem to be used?)

}

Scene2208::~Scene2208() {
	delete _fontSurface;
	delete _backgroundSurface;
	delete _topBackgroundSurface;
	delete _bottomBackgroundSurface;
}

void Scene2208::update() {

	int16 mouseY = _vm->getMouseY();
	
	if (mouseY < 48) {
		if (_currRowIndex > 0)
			_newRowIndex = _currRowIndex - 1;
	} else if (mouseY > 432) {
		if (_currRowIndex < _maxRowIndex - _visibleRowsCount)
			_newRowIndex = _currRowIndex + 1;
	} else {
		if (_currRowIndex > _newRowIndex)
			_newRowIndex = _currRowIndex;
	}

	if (_currRowIndex < _newRowIndex) {
		if (_rowScrollY == 0) {
			drawRow(_currRowIndex + _visibleRowsCount);
		}
		_backgroundScrollY += 4;
		_rowScrollY += 4;
		if (_rowScrollY == 48) {
			_rowScrollY = 0;
			_currRowIndex++;
		}
		_background->getSurface()->getSysRect().y = _backgroundScrollY;
	} else if (_currRowIndex > _newRowIndex || _rowScrollY > 0) {
		if (_rowScrollY == 0) {
			drawRow(_currRowIndex - 1);
			_currRowIndex--;
		}
		_backgroundScrollY -= 4;
		if (_rowScrollY == 0)
			_rowScrollY = 48;
		_rowScrollY -= 4;
		_background->getSurface()->getSysRect().y = _backgroundScrollY;
	}

	// TODO Screen.yOffset = _backgroundScrollY;
	Scene::update();

}

uint32 Scene2208::handleMessage(int messageNum, const MessageParam &param, Entity *sender) {
	uint32 messageResult = Scene::handleMessage(messageNum, param, sender);
	switch (messageNum) {
	case 0x0001:
		if (param.asPoint().x <= 40 || param.asPoint().x >= 600) {
			_parentModule->sendMessage(0x1009, 0, this);
		}
		break;
	}
	return messageResult;
}

void Scene2208::createFontSurface() {
	DataResource fontData(_vm);
	SpriteResource spriteResource(_vm);
	fontData.load(calcHash("asRecFont"));
	uint16 numRows = fontData.getPoint(calcHash("meNumRows")).x;
	uint16 firstChar = fontData.getPoint(calcHash("meFirstChar")).x;
	uint16 charWidth = fontData.getPoint(calcHash("meCharWidth")).x;
	uint16 charHeight = fontData.getPoint(calcHash("meCharHeight")).x;
	NPointArray *tracking = fontData.getPointArray(calcHash("meTracking"));
	spriteResource.load2(0x0800090C);
	_fontSurface = new FontSurface(_vm, tracking, numRows, firstChar, charWidth, charHeight);
	_fontSurface->drawSpriteResourceEx(spriteResource, false, false, 0, 0);
}

void Scene2208::drawRow(int16 rowIndex) {
	NDrawRect sourceRect;	
	int16 y = (rowIndex * 48) % 528;
	if (rowIndex < 4) {
		sourceRect.x = 0;
		sourceRect.y = y;
		sourceRect.width = 640;
		sourceRect.height = 48;
		_background->getSurface()->copyFrom(_topBackgroundSurface->getSurface(), 0, y, sourceRect, true);
	} else if (rowIndex >= _maxRowIndex - 5) {
		sourceRect.x = 0;
		sourceRect.y = (rowIndex - _maxRowIndex + 4) * 48;
		sourceRect.width = 640;
		sourceRect.height = 48;
		_background->getSurface()->copyFrom(_bottomBackgroundSurface->getSurface(), 0, y, sourceRect, true);
	} else {
		rowIndex -= 4;
		sourceRect.x = 0;
		sourceRect.y = (rowIndex * 48) % 480;
		sourceRect.width = 640;
		sourceRect.height = 48;
		_background->getSurface()->copyFrom(_backgroundSurface->getSurface(), 0, y, sourceRect, true);
		if (rowIndex < _strings.size()) {
			const char *text = _strings[rowIndex];
			// TODO/CHECKME: Use temporary string up to '{' character (see above)
			_fontSurface->drawString(_background->getSurface(), 95, y, (const byte*)text);
		}
	}
}

} // End of namespace Neverhood
