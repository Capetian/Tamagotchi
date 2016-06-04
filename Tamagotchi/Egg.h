#ifndef EGG_H_
#define EGG_H_
#include "stdafx.h"

class Egg: public Tamagotchi, public GameObject{
public:
	Egg();
	Egg(GameState object);
	void setImage();
	 void loseHappiness();
	 void getHungry();
	int getHappiness();
	int getHunger();
	int getExperience();
	void play();
	void feed();

	void move(float _x);
	void draw(sf::RenderWindow &window);
	sf::Sprite icon;
	void addExperience();

protected:
    sf::Texture texture;



};

#endif