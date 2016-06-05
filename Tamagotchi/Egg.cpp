#include "stdafx.h"
#include "Egg.h"

Egg::Egg() :GameObject() {
	setImage();
}


Egg::Egg(GameState object) {
	hunger = object.hunger;
	happiness = object.happiness;
	experience = object.experience;
	setImage();
}

void Egg::loseHappiness() {
	happiness -= 2;
}

void Egg::getHungry() {
	hunger += 4;
}
void Egg::play() {
		happiness += 10;
		if (happiness > 100) happiness = 100;
	addExperience();
}

void Egg::feed() {
		hunger -= 5;
		if (hunger <0) hunger = 0;
	addExperience();
}


void Egg::setImage() {

	try {
		texture.loadFromFile("egg1.png");
		icon.setTexture(texture);
		icon.setPosition(x, y);
	}
	catch (exception e) {
		cout << "Error loading texture!" << endl;
	}

}

void Egg::draw(sf::RenderWindow &window)
{
	window.draw(icon);
}

int Egg::getHappiness() {
	return happiness;
}
int Egg::getHunger() {
	return hunger;
}
int Egg::getExperience() {
	return experience;
}

void Egg::addExperience() {
	experience += 10;
}



void Egg::move(float _x) {
	icon.move(_x, 0);
	sf::Vector2f position = icon.getPosition();
	x = position.x;

}