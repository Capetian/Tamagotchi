#include "stdafx.h"
#include "Egg.h"

Egg::Egg():GameObject(100,200) {
	setImage();
	experience = 0;
}

Egg::Egg(string eggName) : GameObject(100, 200) {
	name = eggName;
	setImage();
}

void Egg::loseHealth() {
	health -= 2;
}

void Egg::loseHappiness() {
	happiness -= 5;
}
void Egg::loseEnergy() {
	energy -= 5;
}
void Egg::loseCleanless() {
	cleanliness -= 10;
}

void Egg::getHungry() {
	hunger += 10;
}
void Egg::play() {
	happiness += 10;
	energy -= 5;
	addExperience();
}

void Egg::feed() {
	if (hunger > 0) {
		energy += 2;
		hunger -= 10;
		addExperience();
	}   //TODO: add overfeeding?
}

void Egg::clean() {
	cleanliness += 10;
	happiness -= 2;
	energy -= 2;
}

void Egg::cure() {
	health += 10;
	happiness += 2;
}
void Egg::setImage() {
	
	try {
		texture.loadFromFile("egg1.png");
		icon.setTexture(texture);
		icon.setPosition(100, 200);
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
int Egg::getHealth() {
	return health;
}
int Egg::getCleanless() {
	return cleanliness;
}

int Egg::getExperience() {
	return experience;
}

void Egg::addExperience() {
	experience += 5;
}

void Egg::startSleeping(sf::RenderWindow &window) {
	sf::Texture texture;
	if (!texture.loadFromFile("coco_sleep1.png"))
	{
		cout << "error loading texture" << endl;
		// error...
	}
	cout << "texture loaded" << endl;
	icon.setTexture(texture);
	window.draw(icon);

}

void Egg::move(float _x) {
	cout << "moving" << endl;
	icon.move(_x, 0);
	sf::Vector2f position = icon.getPosition();
	x = position.x;
	//y=position.y;}
}