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
	button.push_back(new Button(160, 240, 2, font, "Top scores"));
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
	for (int i = 0; i < 5; i++) {
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
		//start_new_game(window);
		break;
	case 1:
		//start_loaded_game(window);
		break;
	case 2:
		//top_scores(window);
		break;
	case 3:
		aboutGame(window);
		//info_page1(window);
		break;
	case 4:
		window.close();
		return 1;
		break;
	}
	return 0;
}

int Main_Menu::main_menu(sf::RenderWindow &window)
{
	p_b = button[0];

	//p_b = &buttons[0];
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
					if (p_b->getMenuPosition()<4)
					{
						p_b->buttonUnselected();
						p_b = button[p_b->getMenuPosition() + 1];
						p_b->buttonSelected();
					}
				}
				if (event.key.code == sf::Keyboard::Up)
				{

					if (p_b->getMenuPosition()>0)
					{
						p_b->buttonUnselected();
						p_b = button[p_b->getMenuPosition() - 1];
						p_b->buttonSelected();
					}
				}

			}
		}
		for (int i = 0; i<5; i++)
			button[i]->draw(window);

		window.draw(text);
		window.display();
		window.clear();

	}

	return 0;
}
/*
Pause::Pause() : Main_Menu("Pause")
{
	buttons = new Button[3];
	buttons[0] = Button(160, 100, 0, font, "Back");
	buttons[1] = Button(160, 170, 1, font, "Save & close");
	buttons[2] = Button(160, 240, 2, font, "Close");
}

int Pause::pause_menu(sf::RenderWindow &window, Player &player)
{
	p_b = &buttons[0];
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
					if (selected_position(p_b->getMenuPosition(), window, player) == 1)
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
					if (p_b->getMenuPosition()<2)
					{
						p_b->buttonUnselected();
						p_b = &buttons[p_b->getMenuPosition() + 1];
						p_b->buttonSelected();
					}
				}
				if (event.key.code == sf::Keyboard::Up)
				{

					if (p_b->getMenuPosition()>0)
					{
						p_b->buttonUnselected();
						p_b = &buttons[p_b->getMenuPosition() - 1];
						p_b->buttonSelected();
					}
				}
			}
		}
		for (int i = 0; i<3; i++)
			buttons[i].draw(window);
		window.draw(text);
		window.display();
		window.clear();
	}
	return 0;
}

int Pause::selected_position(int p, sf::RenderWindow &window, Player &player)
{
	switch (p)
	{
	case 0:
		return 1;
		break;
	case 1:
		save_game(player);
		return 0;
		break;
	case 2:
		return 0;
		break;
	}
	return 0;
}

void start_new_game(sf::RenderWindow &window)
{
	Game game(false);
	if (game.play(window) == 0)
	{
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
			if (time>t1)
			{
				return;
			}
			window.draw(text);
			window.display();
			window.clear();

		}
	}
	else
	{
		window.clear();
		sf::Time time;
		sf::Time t1 = sf::seconds(3);
		sf::Clock clock;
		sf::Text text;
		sf::Text text1;
		Font font;
		text.setFont(font.style);
		text.setString("Game Over");
		text.setCharacterSize(30);
		text.setColor(sf::Color::Green);
		text.setPosition(150, 150);

		text1.setFont(font.style);
		text1.setString("Top score!");
		text1.setCharacterSize(30);
		text1.setColor(sf::Color::White);
		text1.setPosition(140, 200);

		while (window.isOpen())
		{
			time = clock.getElapsedTime();
			if (time>t1)
			{
				return;
			}
			window.draw(text);
			window.draw(text1);
			window.display();
			window.clear();

		}
	}
	return;
}

void start_loaded_game(sf::RenderWindow &window)
{
	Game game(true);
	if (game.play(window) == 0)
	{
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
			if (time>t1)
			{
				return;
			}
			window.draw(text);
			window.display();
			window.clear();

		}
	}
	else
	{
		window.clear();
		sf::Time time;
		sf::Time t1 = sf::seconds(3);
		sf::Clock clock;
		sf::Text text;
		sf::Text text1;
		Font font;
		text.setFont(font.style);
		text.setString("Game Over");
		text.setCharacterSize(30);
		text.setColor(sf::Color::Green);
		text.setPosition(150, 150);

		text1.setFont(font.style);
		text1.setString("Top score!");
		text1.setCharacterSize(30);
		text1.setColor(sf::Color::White);
		text1.setPosition(140, 200);

		while (window.isOpen())
		{
			time = clock.getElapsedTime();
			if (time>t1)
			{
				return;
			}
			window.draw(text);
			window.draw(text1);
			window.display();
			window.clear();

		}
	}
	return;
}
*/