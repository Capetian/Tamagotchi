#ifndef BUTTONS_H_
#define BUTTONS_H_


#include "stdafx.h"

using namespace std;

class Button
{
private:
	sf::Text text;
	int menuPosition; //zmienna przechowujaca informacje o pozycji danego guzika w menu
public:
	Button(float _x, float _y, int p, Font &font, string name);
	Button() {};
	void draw(sf::RenderWindow &window);
	//metoda zwracajaca pozycje w menu
	int getMenuPosition();
	//metoda wywolywana gdy guzik zostal zaznaczony przez gracza, zmienia aktualny kolor
	void buttonSelected();
	//metoda wywolywana gdy guzik zostal odznaczony, zmienia kolor
	void buttonUnselected();
};

#endif