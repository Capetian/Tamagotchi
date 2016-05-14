#ifndef TAMAGOTCHI_H_
#define TAMAGOTCHI_H_

#include "stdafx.h"


class Tamagotchi {
public:
	Tamagotchi();
	virtual void setImage(sf::RenderWindow &window) = 0;
	virtual void startSleeping(sf::RenderWindow &window) = 0;
	virtual int getHealth() = 0;
	virtual int getHappiness() = 0;
	virtual int getCleanless() = 0;
	int getEnergy();
	virtual void loseHealth() = 0;
	virtual void loseHappiness() = 0;
	virtual void loseEnergy() = 0;
	virtual void loseCleanless() = 0;
	virtual void getHungry() = 0;
	virtual void play() = 0;
	virtual void feed() = 0;
	virtual void clean() = 0;
	virtual void cure() = 0;

	friend ostream& operator<<(ostream &out, const Tamagotchi *tamagotchi);
protected:
	int happiness;
	int health;
	int cleanless;
	int energy;
	int hunger;
	void getLivingTime();
	sf::Sprite icon;
private:	
	

	int birth;
	sf::Clock clock;
};


#endif