#ifndef GAME_STATE_H_
#define GAME_STATE_H_
#include "stdafx.h"

class GameState {
public:
	GameState();
	int happiness;
	int type;
	int hunger;
	int experience;
	float time;

	friend istream& operator>>(istream &in, GameState &object);
};

#endif