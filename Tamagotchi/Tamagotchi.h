#ifndef TAMAGOTCHI_H_
#define TAMAGOTCHI_H_

#include "stdafx.h"


class Tamagotchi {
public:
	Tamagotchi();
	Tamagotchi(int happiness, int health, int cleanliness, int energy, int hunger);
	virtual void draw(sf::RenderWindow &window)=0;
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
	virtual void addExperience() = 0;
	virtual int getExperience() = 0;
	//virtual void move(float _x) = 0;

	friend ostream& operator<<(ostream &out,Tamagotchi *tamagotchi);
protected:
	int happiness;
	int health;
	int cleanliness;
	int energy;
	int hunger;
	void getLivingTime();

private:	
	

	float birth;
	sf::Clock clock;
};


#endif