#ifndef EGG_H_
#define EGG_H_
#include "stdafx.h"

class Egg: public Tamagotchi, public GameObject{
public:
	Egg();
	Egg(string name);
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
	sf::Sprite icon;
protected:
    sf::Texture texture;
	string name;


};

#endif