#ifndef BALL_H_
#define BALL_H_
#include "stdafx.h"

class Ball : public GameObject {
private:
	sf::Sprite icon;
	sf::Texture texture;
public:
	//konstruktor przyjmujacy jako argumenty wspolrzedne x i y
	Ball(float _x, float _y);

	//metoda rysujaca ksztalt wroga w aktywnym oknie
	void draw(sf::RenderWindow &window);

	//wirtualna metoda zmieniajaca polozenie wroga
	void move(int speed);
};

#endif