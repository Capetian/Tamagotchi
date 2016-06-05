#include "stdafx.h"
#include "Chicken.h"

Chicken::Chicken(GameState object) {
	hunger = object.hunger;
	happiness = object.happiness;
	experience = object.experience;
	setImage();
}

Chicken::Chicken() {
	setImage();
}
Chicken::Chicken(Egg egg) {
	hunger = egg.getHunger();
	happiness = egg.getHappiness();
	x = egg.returnx();
	y = egg.returny();
	setImage();

}


void Chicken::loseHappiness() {
	happiness -= 5;
}


void Chicken::getHungry() {
	hunger += 10;
}
void Chicken::play() {
		happiness += 5;
		if (happiness > 100) happiness = 100;
	addExperience();

}

void Chicken::feed() {
		hunger -= 3;
		if (hunger <0) hunger = 0;
	addExperience();

}


void Chicken::setImage() {
	try {
		texture.loadFromFile("coco1.png");
		icon.setTexture(texture);
	}
	catch (exception e) {
		cout << "Error loading texture!" << endl;
	}
	icon.setPosition(x, y);


}

void Chicken::addExperience() {
	experience += 5;
}

void Chicken::draw(sf::RenderWindow &window)
{
	window.draw(icon);
}

int Chicken::getHappiness() {
	return happiness;
}

void Chicken::move(float _x)
{
	icon.move(_x, 0);
	sf::Vector2f position = icon.getPosition();
	x = position.x;
}