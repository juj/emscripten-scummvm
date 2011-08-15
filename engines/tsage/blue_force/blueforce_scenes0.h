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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef TSAGE_BLUEFORCE_SCENES0_H
#define TSAGE_BLUEFORCE_SCENES0_H

#include "common/scummsys.h"
#include "tsage/blue_force/blueforce_logic.h"
#include "tsage/converse.h"
#include "tsage/events.h"
#include "tsage/core.h"
#include "tsage/scenes.h"
#include "tsage/globals.h"
#include "tsage/sound.h"

namespace tSage_BlueForce {

using namespace tSage;

class Scene20 : public SceneExt {
	/* Actions */
	class Action1 : public Action {
	private:
		ASoundExt _sound;
	public:
		virtual void signal();
	};
public:
	Action1 _action1;
	ScenePalette _scenePalette;
	SceneObject _object1, _object2, _object3, _object4;
	SceneObject _object5, _object6, _object7, _object8;

	virtual void postInit(SceneObjectList *OwnerList = NULL);
};

class Scene50: public SceneExt {
	class Tooltip: public SavedObject {
	public:
		Rect _bounds;
		char _msg[80];
		int _field60;
		int _field62;
	public:
		Tooltip();

		virtual Common::String getClassName() { return "Scene50_Tooltip"; }
		virtual void synchronize(Serializer &s);
	};
	class Tooltip2: public Action {
	public:
		Tooltip2(): Action() {}

		virtual Common::String getClassName() { return "Scene50_Tooltip2"; }
		virtual void signal();
		virtual void dispatch();
	};
public:

};

} // End of namespace tSage_BlueForce

#endif