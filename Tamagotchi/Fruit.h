#ifndef FRUIT_H_
#define FRUIT_H_
#include "stdafx.h"

class Fruit : public GameObject{
private:
	sf::Sprite icon;
	sf::Texture texture;
public:
	//konstruktor przyjmujacy jako argumenty wspolrzedne x i y
	Fruit(float _x, float _y);

	//metoda rysujaca ksztalt wroga w aktywnym oknie
	void draw(sf::RenderWindow &window);

	//wirtualna metoda zmieniajaca polozenie wroga
	 void move(int speed);
};

#endif