#include "stdafx.h"
#include "Chicken.h"

Chicken::Chicken() {

}

Chicken::Chicken(Tamagotchi *tamagotchi) {
	health = tamagotchi->getHealth();
	happiness = tamagotchi->getHappiness();
	cleanliness = tamagotchi->getCleanless();
	energy = tamagotchi->getEnergy();
	//hunger = egg->getHungry();

}
void Chicken::loseHealth() {
	health -= 2;
}

void Chicken::loseHappiness() {
	happiness -= 5;
}
void Chicken::loseEnergy() {
	energy -= 5;
}
void Chicken::loseCleanless() {
	cleanliness -= 10;
}

void Chicken::getHungry() {
	hunger += 10;
}
void Chicken::play() {
	happiness += 10;
	energy -= 5;
}

void Chicken::feed() {
	if (hunger > 0) {
		energy += 2;
		hunger -= 10;
	}   //TODO: add overfeeding?
}

void Chicken::clean() {
	cleanliness += 10;
	happiness -= 2;
	energy -= 2;
}

void Chicken::cure() {
	health += 10;
	happiness += 2;
}
void Chicken::setImage(sf::RenderWindow &window) {
	sf::Texture texture;
	try {
		texture.loadFromFile("coco1.png");
		icon.setTexture(texture);
	}
	catch (exception e) {
		cout << "Error loading texture!" << endl;
	}

	icon.setPosition(100, 200);
	window.draw(icon);

}
int Chicken::getHappiness() {
	return happiness;
}
int Chicken::getHealth() {
	return health;
}
int Chicken::getCleanless() {
	return cleanliness;
}


void Chicken::startSleeping(sf::RenderWindow &window) {
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