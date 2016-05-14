#include "stdafx.h"
#include "Game.h"

Game::Game() {
	t1 = sf::seconds(5);
	t2 = sf::seconds(5);

	text_play.setFont(font.style);
	text_play.setString("PLAY");
	text_play.setCharacterSize(20);
	text_play.setColor(sf::Color::White);
	text_play.setPosition(320, 50);



}

Game::Game(bool loaded) {
	t1 = sf::seconds(10);
	t2 = sf::seconds(5);

	text_play.setFont(font.style);
	text_play.setString("1-PLAY");
	text_play.setCharacterSize(20);
	text_play.setColor(sf::Color::White);
	text_play.setPosition(20, 20);

	text_feed.setFont(font.style);
	text_feed.setString("2-FEED");
	text_feed.setCharacterSize(20);
	text_feed.setColor(sf::Color::White);
	text_feed.setPosition(200, 20);

	text_clean.setFont(font.style);
	text_clean.setString("3-CLEAN");
	text_clean.setCharacterSize(20);
	text_clean.setColor(sf::Color::White);
	text_clean.setPosition(380, 20);

	title_health.setFont(font.style);
	title_health.setString("HEALTH");
	title_health.setCharacterSize(20);
	title_health.setColor(sf::Color::Green);
	title_health.setPosition(700, 20);

	text_health.setFont(font.style);
	text_health.setCharacterSize(20);
	text_health.setColor(sf::Color::Green);
	text_health.setPosition(700, 40);

	title_energy.setFont(font.style);
	title_energy.setString("ENERGY");
	title_energy.setCharacterSize(20);
	title_energy.setColor(sf::Color::Green);
	title_energy.setPosition(700, 80);

	text_energy.setFont(font.style);
	text_energy.setCharacterSize(20);
	text_energy.setColor(sf::Color::Green);
	text_energy.setPosition(700, 100);

	title_happiness.setFont(font.style);
	title_happiness.setString("Happiness");
	title_happiness.setCharacterSize(20);
	title_happiness.setColor(sf::Color::Green);
	title_happiness.setPosition(700, 140);

	text_happiness.setFont(font.style);
	text_happiness.setCharacterSize(20);
	text_happiness.setColor(sf::Color::Green);
	text_happiness.setPosition(700, 160);

	title_cleanless.setFont(font.style);
	title_cleanless.setString("Cleanless");
	title_cleanless.setCharacterSize(20);
	title_cleanless.setColor(sf::Color::Green);
	title_cleanless.setPosition(700, 200);
	
	text_cleanless.setFont(font.style);
	text_cleanless.setCharacterSize(20);
	text_cleanless.setColor(sf::Color::Green);
	text_cleanless.setPosition(700, 220);

	sf::Vector2f size;
	size.x = 580;
	size.y = 50;

	rectangle_up.setFillColor(sf::Color::Transparent);
	rectangle_up.setOutlineColor(sf::Color::White);
	rectangle_up.setOutlineThickness(1);
	rectangle_up.setPosition(10, 10);
	rectangle_up.setSize(size);

	rectangle_down.setFillColor(sf::Color::Transparent);
	rectangle_down.setOutlineColor(sf::Color::White);
	rectangle_down.setOutlineThickness(1);
	rectangle_down.setPosition(10, 400);
	rectangle_down.setSize(size);

	Tamagotchi *tamagotchi = new Egg("Ala");
	tamaVector.push_back(tamagotchi);
	tamagotchiCount++;
	
}

int Game::play(sf::RenderWindow &window) {
	while (window.isOpen())
	{
		sf::Event event;
 		while (window.pollEvent(event))
		{
			//jezeli zamknieto okno
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
				//jezeli nacisnieta zostala spacja, generowana jest nowa kula
				if (event.key.code == sf::Keyboard::Space)
				{
					sf::CircleShape shape(50);
					shape.setFillColor(sf::Color::Blue);
					window.draw(shape);
				
				}
			//nacisnieto 1 - bawimy sie
			if (event.key.code == sf::Keyboard::Num1) {
				tamaVector[tamagotchiCount-1]->play();
			}

			if (event.key.code == sf::Keyboard::Num2) {
				tamaVector[tamagotchiCount - 1]->feed();
			}

			if (event.key.code == sf::Keyboard::Num3) {
				tamaVector[tamagotchiCount - 1]->clean();
			}
			if (event.key.code == sf::Keyboard::Num4) {
				tamaVector[tamagotchiCount - 1]->cure();
			}

			//jezeli nacisniety zostal klawisz escape, przechodzimy do trybu pauzy
			if (event.key.code == sf::Keyboard::Escape)
			{
				Pause pause;
				if (pause.pause_menu(window, tamaVector[tamagotchiCount-1]) == 0)
					window.close();
			}
		}

		//poruszanie sie graczem za pomoca strzalek
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
		
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
		
		}

		time = clock.getElapsedTime();
		//jezeli zmierzony czas jest wiekszy od zmiennej t1 (2 sek) generowany jest nowy wrog
		if (time>t1)
		{
			tamaVector[tamagotchiCount - 1]->loseHealth();
			clock.restart();
		}

		time = clock_PU.getElapsedTime();
		//jezeli zmierzony czas jest wiekszy od zmiennej t1 (5 sek) generowany jest nowy bonus
		if (time>t2)
		{
			
		}

		//obsluga rysowania i ruchu wrogow
	

		

	

	


		//przejscie do funkcji wyswietlajacej na ekranie pole do gry, wynik, poziom
		show_info(window);
		window.display();
		window.clear();

	}
	return 0;
}

void Game::show_info(sf::RenderWindow &window)
{


	int tamaHealth = tamaVector[tamagotchiCount - 1]->getHealth();
	int tamaHappiness = tamaVector[tamagotchiCount - 1]->getHappiness();
	int tamaCleanless = tamaVector[tamagotchiCount - 1]->getCleanless();
	int tamaEnergy = tamaVector[tamagotchiCount - 1]->getEnergy();

	text_health.setString(int2str(tamaHealth));
	text_happiness.setString(int2str(tamaHappiness));
	text_cleanless.setString(int2str(tamaCleanless));
	text_energy.setString(int2str(tamaEnergy));

	window.draw(title_health);
	window.draw(title_happiness);
	window.draw(title_cleanless);
	window.draw(title_energy);
	
	window.draw(text_health);
	window.draw(text_happiness);
	window.draw(text_cleanless);
	window.draw(text_energy);
	window.draw(text_play);
	window.draw(text_feed);
	window.draw(text_clean);
	window.draw(rectangle_up);
	window.draw(rectangle_down);
	tamaVector[tamagotchiCount - 1]->setImage(window);
}