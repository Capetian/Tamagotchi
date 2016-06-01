#include "stdafx.h"
#include "Fruit.h"

Fruit::Fruit(float _x, float _y) : GameObject(_x, _y){
	int type = rand() % 5;
	try {
		switch (type) {
		case(0): texture.loadFromFile("strawberry30.png");
			break;
		case(1): texture.loadFromFile("banana34.png");
			break;
		case(2): texture.loadFromFile("cherry33.png");
			break;
		case(3) : texture.loadFromFile("apple33.png");
			break;
		case(4) : texture.loadFromFile("pear34.png");
			break;
		}
		
		icon.setTexture(texture);
		icon.setPosition(_x, _y);
	}
	catch (exception e) {
		cout << "Error loading texture!" << endl;
	}
}

void Fruit::move(int speed)
{
	icon.move(0, speed);
	sf::Vector2f position = icon.getPosition();
	y = position.y;
}

void Fruit::draw(sf::RenderWindow &window)
{
	window.draw(icon);
}