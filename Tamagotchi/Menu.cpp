#include "stdafx.h"
#include "Menu.h"


Main_Menu::Main_Menu()
{

	text.setFont(font.style);
	text.setString("Tamagotchi");
	text.setPosition(160, 30);
	text.setCharacterSize(30);
	text.setColor(sf::Color::Blue);
	button.push_back(new Button(160, 100, 0, font, "New game"));
	button.push_back(new Button(160, 170, 1, font, "Load game"));
	button.push_back(new Button(160, 310, 3, font, "Info?"));
	button.push_back(new Button(160, 380, 4, font, "Close"));

}

Main_Menu::Main_Menu(string name)
{
	text.setFont(font.style);
	text.setString(name);
	text.setPosition(50, 250);
	text.setCharacterSize(30);
	text.setRotation(270);
	text.setColor(sf::Color::Green);
}

Main_Menu::~Main_Menu()
{

	for (int i = 0; i < button.size(); i++) {
		button[i] = NULL;
		delete button[i];
	}
	p_b = NULL;
	delete p_b;
}

int Main_Menu::selected_position(int p, sf::RenderWindow &window)
{
	switch (p)
	{
	case 0:
		startGame(window, false);
		//start_new_game(window);
		break;
	case 1:
		startGame(window, true);
		break;
	case 2:
		aboutGame(window);
		break;
	case 3:
		window.close();
		return 1;
		break;
	}
	return 0;
}

int Main_Menu::main_menu(sf::RenderWindow &window)
{
	p_b = button[0];


	p_b->buttonSelected();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return 0;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Return)
				{
					if (selected_position(p_b->getMenuPosition(), window) == 1)
					{

						return 0;
					}
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					if (p_b->getMenuPosition() < 3)
					{
						p_b->buttonUnselected();
						p_b = button[p_b->getMenuPosition() + 1];
						p_b->buttonSelected();
					}
				}
				if (event.key.code == sf::Keyboard::Up)
				{

					if (p_b->getMenuPosition() > 0)
					{
						p_b->buttonUnselected();
						p_b = button[p_b->getMenuPosition() - 1];
						p_b->buttonSelected();
					}
				}

			}
		}
		for (int i = 0; i < 4; i++)
			button[i]->draw(window);

		window.draw(text);
		window.display();
		window.clear();

	}

	return 0;
}

void startGame(sf::RenderWindow &window, bool loaded) {

	Game game(loaded);
	if (game.play(window) == 0) {
		window.clear();
		sf::Time time;
		sf::Time t1 = sf::seconds(3);
		sf::Clock clock;
		sf::Text text;
		Font font;
		text.setFont(font.style);
		text.setString("Game Over");
		text.setCharacterSize(30);
		text.setColor(sf::Color::Green);
		text.setPosition(150, 150);

		while (window.isOpen())
		{
			time = clock.getElapsedTime();
			if (time > t1)
			{
				return;
			}
			window.draw(text);
			window.display();
			window.clear();

		}
	}

	return;
}

Pause::Pause() : Main_Menu("Pause")
{
	button.push_back(new Button(160, 100, 0, font, "Back"));
	button.push_back(new Button(160, 170, 1, font, "Save + close"));
	button.push_back(new Button(160, 240, 2, font, "Close"));

}

Pause::~Pause() {
	for (int i = 0; i < button.size(); i++)
		delete button[i];
}



int Pause::pause_menu(sf::RenderWindow &window, Tamagotchi *tamagotchi)
{
	p_b = button[0];
	p_b->buttonSelected();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return 0;
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Return)
				{
					if (selected_position(p_b->getMenuPosition(), window, tamagotchi) == 1)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}

				if (event.key.code == sf::Keyboard::Down)
				{
					if (p_b->getMenuPosition() < 2)
					{
						p_b->buttonUnselected();
						p_b = button[p_b->getMenuPosition() + 1];
						p_b->buttonSelected();
					}
				}
				if (event.key.code == sf::Keyboard::Up)
				{

					if (p_b->getMenuPosition() > 0)
					{
						p_b->buttonUnselected();
						p_b = button[p_b->getMenuPosition() - 1];
						p_b->buttonSelected();
					}
				}
			}
		}
		for (int i = 0; i < 3; i++)
			button[i]->draw(window);
		window.draw(text);
		window.display();
		window.clear();
	}
	return 0;
}

int Pause::selected_position(int p, sf::RenderWindow &window, Tamagotchi *tamagotchi)
{
	switch (p)
	{
	case 0:
		return 1;
		break;
	case 1:
		save_game(tamagotchi);
		return 0;
		break;
	case 2:
		return 0;
		break;
	}
	return 0;
}