#include "stdafx.h"
#include "GameState.h"

GameState::GameState() {
	type = 0;
	happiness = 20;
	hunger = 50;
	experience = 0;
	time = 0;

}
istream& operator>>(istream &in, GameState &object) {
	GameState temp;
	if (in >> temp.type) {
		if (in >> temp.happiness) {
			if (in >> temp.experience) {
				if (in >> temp.hunger) {
					if (in >> temp.time) {
						object = temp;
						return in;
					}
				}
			}
		}
	}
	in.clear();
	throw UnloadedGame();
	return in;
}