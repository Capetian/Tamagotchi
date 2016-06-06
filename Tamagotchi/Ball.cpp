#include "stdafx.h"
#include "Ball.h"

Ball::Ball(float _x, float _y) : GameObject(_x, _y) {

	try {

		texture.loadFromFile("basketball.png");
		icon.setTexture(texture);
		icon.setPosition(_x, _y);
	}
	catch (exception e) {
		cout << "Error loading texture!" << endl;
	}
}

void Ball::move(int speed)
{
	icon.move(0, speed);
	sf::Vector2f position = icon.getPosition();
	y = position.y;
}

void Ball::draw(sf::RenderWindow &window)
{
	window.draw(icon);
}