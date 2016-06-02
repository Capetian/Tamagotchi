#include "stdafx.h"
#include "AbstractObject.h"

AbstractObject::AbstractObject() {
	type = 0;
	happiness = 0;
	hunger = 0;
	experience = 0;

}
istream& operator>>(istream &in, AbstractObject &object) {
	AbstractObject temp;
	if (in >> temp.type) {
		if (in >> temp.happiness) {
			if (in >> temp.experience) {
				if (in >> temp.hunger) {
					object = temp;
					return in;
				}
			}
		}
	}
	in.clear();
	throw UnloadedGame();
	return in;
}