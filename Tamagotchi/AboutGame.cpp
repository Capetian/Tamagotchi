#include "stdafx.h"
#include "AboutGame.h"

int aboutGame(sf::RenderWindow &window)
{

	Font font;
	font.style.getLineSpacing(3);
	sf::Text line0;
	sf::Text line1;
	sf::Text line2;
	sf::Text line3;
	sf::Text line4;

	line0.setFont(font.style);
	line1.setFont(font.style);
	line2.setFont(font.style);
	line3.setFont(font.style);
	line4.setFont(font.style);
	line0.setString("Info 1/3");
	line0.setCharacterSize(20);
	line0.setPosition(180, 10);
	line1.setString("Player:");
	line1.setCharacterSize(20);
	line1.setPosition(180, 50);
	line2.setString("Use:");
	line2.setCharacterSize(20);
	line2.setPosition(40, 135);
	line3.setString("to move");
	line3.setCharacterSize(20);
	line3.setPosition(200, 135);
	line4.setString("and spacebar to shoot");
	line4.setCharacterSize(20);
	line4.setPosition(40, 180);



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
				if (event.key.code == sf::Keyboard::Right)
				{
				
					return 0;
				}

			}
		}

		window.draw(line0);
		window.draw(line1);
		window.draw(line2);
		window.draw(line3);
		window.draw(line4);


		window.display();
		window.clear();

	}
	return 0;
}