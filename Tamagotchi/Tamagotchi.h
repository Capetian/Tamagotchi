#ifndef TAMAGOTCHI_H_
#define TAMAGOTCHI_H_

#include "stdafx.h"


class Tamagotchi {
public:
	Tamagotchi();
	Tamagotchi(int happiness, int hunger, int experience);
	virtual void draw(sf::RenderWindow &window)=0;
	virtual int getHappiness() = 0;
	virtual int getHunger() = 0;
	virtual int getExperience() = 0;
	virtual void play() = 0;
	virtual void feed() = 0;
	virtual void loseHappiness() = 0;
	virtual void getHungry() = 0;

	//virtual int getCleanless() = 0;
	//int getEnergy();
	//virtual void loseHealth() = 0;

	//virtual void loseEnergy() = 0;
	//virtual void loseCleanless() = 0;
	//virtual void getHungry() = 0;

	//virtual void clean() = 0;
	//virtual void cure() = 0;




	friend ostream& operator<<(ostream &out,Tamagotchi *tamagotchi);
	friend istream& operator>>(istream &in, Tamagotchi &tamagotchi);
protected:
	int happiness;
	int experience;
	int hunger;
	void getLivingTime();

private:	
	

	float birth;
	sf::Clock clock;
};


#endif