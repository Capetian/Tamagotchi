#include "stdafx.h"
#include "Dragon.h"

Dragon::Dragon(AbstractObject object) {
	hunger = object.hunger;
	happiness = object.happiness;
	experience = object.experience;
	setImage();
}

Dragon::Dragon() {
	setImage();
}
Dragon::Dragon(Chicken chicken) {
	hunger = chicken.getHunger();
	happiness = chicken.getHappiness();
	x = chicken.returnx();
	y = chicken.returny();
	setImage();

}


void Dragon::loseHappiness() {
	happiness -= 20;
}


void Dragon::getHungry() {
	hunger += 30;
}
void Dragon::play() {
	happiness += 3;

}

void Dragon::feed() {
	if (hunger > 2) {
		hunger -= 2;
		addExperience();
	}
}


void Dragon::setImage() {
	try {
		texture.loadFromFile("dragon1.png");
		icon.setTexture(texture);
	}
	catch (exception e) {
		cout << "Error loading texture!" << endl;
	}
	icon.setPosition(x, y);
}

void Dragon::addExperience() {
	experience += 3;
}

void Dragon::draw(sf::RenderWindow &window)
{
	window.draw(icon);
}

int Dragon::getHappiness() {
	return happiness;
}

void Dragon::move(float _x)
{
	icon.move(_x, 0);
	sf::Vector2f position = icon.getPosition();
	x = position.x;
}