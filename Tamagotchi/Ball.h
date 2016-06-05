#ifndef BALL_H_
#define BALL_H_
#include "stdafx.h"

class Ball : public GameObject {
private:
	sf::Sprite icon;
	sf::Texture texture;
public:
	Ball(float _x, float _y);

	void draw(sf::RenderWindow &window);

	void move(int speed);
};

#endif