#ifndef FRUIT_H_
#define FRUIT_H_
#include "stdafx.h"

class Fruit : public GameObject{
private:
	sf::Sprite icon;
	sf::Texture texture;
public:
	Fruit(float _x, float _y);
	void draw(sf::RenderWindow &window);
	 void move(int speed);
};

#endif