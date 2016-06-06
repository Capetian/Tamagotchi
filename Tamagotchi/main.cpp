
#include "stdafx.h"
#include "Menu.h"
#include <conio.h>
#include <SFML/Graphics.hpp>


int main(){
	sf::RenderWindow window(sf::VideoMode(900,460), "TAMAGOTCHI!");
	window.setFramerateLimit(20);
	Main_Menu menu;
	while (window.isOpen())
	{

		if (menu.main_menu(window) == 0)
			window.close();
	}
	
	_getch();
	return 0;
}