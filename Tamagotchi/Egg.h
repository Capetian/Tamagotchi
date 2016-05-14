#ifndef EGG_H_
#define EGG_H_
#include "stdafx.h"

class Egg: public Tamagotchi{
public:
	Egg();
	Egg(string name);
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
private:

	string name;

};

#endif