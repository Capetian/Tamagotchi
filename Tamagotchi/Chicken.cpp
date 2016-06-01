#include "stdafx.h"
#include "Chicken.h"

Chicken::Chicken() {
	
}

Chicken::Chicken(Egg egg) {
	health = egg.getHealth();
	happiness = egg.getHappiness();
	cleanliness = egg.getCleanless();
	energy = egg.getEnergy();
	x = egg.returnx();
	y = egg.returny();
	//hunger = egg->getHungry();
	setImage();

	

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
void Chicken::setImage() {
	//sf::Texture texture;
	try {
		texture.loadFromFile("coco1.png");
		icon.setTexture(texture);
	}
	catch (exception e) {
		cout << "Error loading texture!" << endl;
	}

	icon.setPosition(returnx(), returny());


}

void Chicken::addExperience() {
	experience += 3;
}

void Chicken::draw(sf::RenderWindow &window)
{
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

void Chicken::move(float _x)
{
	cout << "moving" << endl;
	icon.move(_x, 0);
	sf::Vector2f position = icon.getPosition();
	x = position.x;
	//y=position.y;
}