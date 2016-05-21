#ifndef CHICKEN_H_
#define CHICKEN_H_
#include "stdafx.h"

class Chicken: public Tamagotchi {
public:
	Chicken();
	Chicken(Tamagotchi *tamagotchi);
	void startSleeping(sf::RenderWindow &window);
	void setImage(sf::RenderWindow &window);
	void loseHealth();
	void loseHappiness();
	void loseEnergy();
	void loseCleanless();
	void getHungry();
	int getHappiness();
	int getHealth();
	int getCleanless();
	void play();
	void feed();
	void clean();
	void cure();

};

#endif
