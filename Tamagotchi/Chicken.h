#ifndef CHICKEN_H_
#define CHICKEN_H_
#include "stdafx.h"

class Chicken: public Egg {
public:
	Chicken();
	Chicken(GameState object);
	Chicken(Egg egg);
	void setImage();
	void loseHappiness();
	void getHungry();
	int getHappiness();
	void play();
	void feed();
	void move(float _x);
	void draw(sf::RenderWindow &window);
	void addExperience();

};

#endif
