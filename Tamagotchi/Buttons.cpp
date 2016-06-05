#include "stdafx.h"
#include "Buttons.h"


Button::Button(float _x, float _y, int p, Font &font, string name){
	menuPosition = p;
	text.setFont(font.style);
	text.setCharacterSize(30);
	text.setColor(sf::Color::White);
	text.setPosition(_x + 10, _y + 10);
	text.setString(name);
}


void Button::draw(sf::RenderWindow &window){

	window.draw(text);
}

int Button::getMenuPosition()
{
	return menuPosition;
}


void Button::buttonSelected(){
	text.setColor(sf::Color::Green);
}

void Button::buttonUnselected(){
	text.setColor(sf::Color::White);
}



