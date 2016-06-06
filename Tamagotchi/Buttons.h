#ifndef BUTTONS_H_
#define BUTTONS_H_


#include "stdafx.h"

using namespace std;

class Button
{
private:
	sf::Text text;
	int menuPosition; 
public:
	Button(float _x, float _y, int p, Font &font, string name);
	Button() {};
	void draw(sf::RenderWindow &window);
	int getMenuPosition();
	void buttonSelected();
	void buttonUnselected();
};

#endif