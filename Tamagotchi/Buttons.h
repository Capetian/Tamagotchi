#include "Interface.h"
#include "AboutGame.h"


#ifndef BUTTONS_H_
#define BUTTONS_H_
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "stdafx.h"
#include <iostream>
using namespace std;

class Button
{
private:
	sf::Text text;
	int menuPosition; //zmienna przechowujaca informacje o pozycji danego guzika w menu
public:
	Button(float _x, float _y, int p, Font &font, string name);
	Button() {};
	//metoda rysujaca obiekt w aktualnie otwartym oknie
	void draw(sf::RenderWindow &window);
	//metoda zwracajaca pozycje w menu
	int getMenuPosition();
	//metoda wywolywana gdy guzik zostal zaznaczony przez gracza, zmienia aktualny kolor
	void buttonSelected();
	//metoda wywolywana gdy guzik zostal odznaczony, zmienia kolor
	void buttonUnselected();
};

#endif