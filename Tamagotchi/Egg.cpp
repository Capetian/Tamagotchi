#include "stdafx.h"
#include "Egg.h"

Egg::Egg() {

}

Egg::Egg(string eggName) {
	name = eggName;
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
	cleanless -= 10;
}

void Egg::getHungry() {
	hunger += 10;
}
void Egg::play() {
	happiness += 10;
	energy -= 5;
}

void Egg::feed() {
	if (hunger > 0) {
		energy += 2;
		hunger -= 10;
	}   //TODO: add overfeeding?
}

void Egg::clean() {
	cleanless += 10;
	happiness -= 2;
	energy -= 2;
}

void Egg::cure() {
	health += 10;
	happiness += 2;
}
void Egg::setImage(sf::RenderWindow &window) {
	sf::Texture texture;
	try {
		texture.loadFromFile("coco1.png");
		icon.setTexture(texture);
	}
	catch (exception e) {
		cout << "Error loading texture!" << endl;
	}

	window.draw(icon);
	
}
int Egg::getHappiness() {
	return happiness;
}
int Egg::getHealth() {
	return health;
}
int Egg::getCleanless() {
	return cleanless;
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