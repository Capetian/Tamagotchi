#ifndef CHICKEN_H_
#define CHICKEN_H_
#include "stdafx.h"

class Chicken: public Egg {
public:
	Chicken();
	Chicken(Egg egg);
	void startSleeping(sf::RenderWindow &window);
	void setImage();
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
	void move(float _x);
	void draw(sf::RenderWindow &window);
	void addExperience();
//private:
//	static sf::Texture texture;

};

#endif
