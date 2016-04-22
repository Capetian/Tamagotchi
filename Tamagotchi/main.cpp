
#include "stdafx.h"
#include "Menu.h"

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600,500), "TAMAGOTCHI!");
	Main_Menu menu;
	while (window.isOpen())
	{
		if (menu.main_menu(window) == 0)
			window.close();
	}


	return 0;
}