#ifndef DRAGON_H_
#define DRAGON_H_
#include "stdafx.h"

class Dragon : public Egg {
public:
	Dragon();
	Dragon(AbstractObject object);
	Dragon(Chicken chicken);

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
