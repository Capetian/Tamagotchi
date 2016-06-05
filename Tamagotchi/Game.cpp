#include "stdafx.h"
#include "Game.h"

Game::~Game() {
	for (int i = 0; i < tamaVector.size(); i++) {
		delete tamaVector[i];
	}
	for (int i = 0; i < fruits.size(); i++) {
		delete fruits[i];
	}
	for (int i = 0; i < balls.size(); i++) {
		delete balls[i];
	}

}


Game::Game(bool loaded) {
	tamagotchiCount = 0;
	font_numb.style.loadFromFile("number.ttf");
	t1 = sf::seconds(20);
	t2 = sf::seconds(3);
	t3 = sf::seconds(10);

	timeBetweenTransformations = sf::seconds(60);
	timeToGrowUp = sf::seconds(10);
	timeBetweenBalls = sf::seconds(0.3);
	timeBetweenFood = sf::seconds(2);

	text_play.setFont(font.style);
	text_play.setString("1-PLAY");
	text_play.setCharacterSize(30);
	text_play.setColor(sf::Color::White);
	text_play.setPosition(20, 20);

	text_feed.setFont(font.style);
	text_feed.setString("2-FEED");
	text_feed.setCharacterSize(30);
	text_feed.setColor(sf::Color::White);
	text_feed.setPosition(400, 20);


	title_hunger.setFont(font.style);
	title_hunger.setString("HUNGER");
	title_hunger.setCharacterSize(30);
	title_hunger.setColor(sf::Color::Green);
	title_hunger.setPosition(640, 20);

	text_hunger.setFont(font_numb.style);
	text_hunger.setCharacterSize(36);
	text_hunger.setColor(sf::Color::Green);
	text_hunger.setPosition(690, 60);

	title_experience.setFont(font.style);
	title_experience.setString("EXP");
	title_experience.setCharacterSize(30);
	title_experience.setColor(sf::Color::Green);
	title_experience.setPosition(640, 110);

	text_experience.setFont(font_numb.style);
	text_experience.setCharacterSize(36);
	text_experience.setColor(sf::Color::Green);
	text_experience.setPosition(690, 150);

	title_happiness.setFont(font.style);
	title_happiness.setString("HAPPY");
	title_happiness.setCharacterSize(30);
	title_happiness.setColor(sf::Color::Green);
	title_happiness.setPosition(640, 200);

	text_happiness.setFont(font_numb.style);
	text_happiness.setCharacterSize(36);
	text_happiness.setColor(sf::Color::Green);
	text_happiness.setPosition(690, 240);



	sf::Vector2f size;
	size.x = 580;
	size.y = 50;

	sf::Vector2f size_line;
	size_line.x = 580;
	size_line.y = 1;

	bottom_line.setPosition(0, 370);
	bottom_line.setSize(size_line);

	rectangle_up.setFillColor(sf::Color::Transparent);
	rectangle_up.setOutlineColor(sf::Color::White);
	rectangle_up.setOutlineThickness(1);
	rectangle_up.setPosition(10, 10);
	rectangle_up.setSize(size);

	if (loaded) {
		GameState object = getTamagotchiFromFile();
		switch (object.type) {
		case 0:
			tamagotchi = new Egg(object);
			break;
		case 1:
			tamagotchi = new Chicken(object);
			break;
		case 2:
			tamagotchi = new Dragon(object);
			break;
		default:
			tamagotchi = new Egg();
			break;
		}
		addedTime = sf::seconds(object.time);
	}
	else {

		tamagotchi = new Egg();
		addedTime = sf::seconds(0);
	}

	tamaVector.push_back(tamagotchi);
	tamagotchiCount++;


}


int Game::play(sf::RenderWindow &window) {
	Tamagotchi *tamagotchi;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			//jezeli zamknieto okno
			if (event.type == sf::Event::Closed)
				window.close();


			//nacisnieto 1 - bawimy sie
			if (event.key.code == sf::Keyboard::Num1) {
				if (!isPlaying && !isEating)
					isPlaying = true;
			}

			if (event.key.code == sf::Keyboard::Num2) {
				if (!isEating && !isPlaying)
					isEating = true;
			}

			//jezeli nacisniety zostal klawisz escape, przechodzimy do trybu pauzy
			if (event.key.code == sf::Keyboard::Escape)
			{
				Pause pause;
				if (pause.pause_menu(window, tamaVector[tamagotchiCount - 1], clockTransformation.getElapsedTime()) == 0)
					window.close();
			}
		}

		//poruszanie sie tamagotchi za pomoca strzalek
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			tamagotchi = tamaVector[tamagotchiCount - 1];
			try {
				Egg &egg = dynamic_cast<Egg &>(*tamagotchi);
				if (egg.returnx() > 0)
					egg.move(-12);
			}
			catch (bad_cast&) {
				try {
					Chicken &chicken = dynamic_cast<Chicken &>(*tamagotchi);
					if (chicken.returnx() > 0)
						chicken.move(-16);
				}
				catch (bad_cast&) {
					try {
						Dragon &dragon = dynamic_cast<Dragon &>(*tamagotchi);
						if (dragon.returnx() > 0)
							dragon.move(-20);
					}
					catch (bad_cast&) {
						cout << "Bad cast" << endl;
					}
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			tamagotchi = tamaVector[tamagotchiCount - 1];
			try {
				Egg &egg = dynamic_cast<Egg &>(*tamagotchi);
				if (egg.returnx() < 500)
					egg.move(12);
			}
			catch (bad_cast&) {
				try {
					Chicken &chicken = dynamic_cast<Chicken &>(*tamagotchi);
					if (chicken.returnx() < 500)
						chicken.move(16);
				}
				catch (bad_cast&) {
					try {
						Dragon &dragon = dynamic_cast<Dragon &>(*tamagotchi);
						if (dragon.returnx() < 500)
							dragon.move(20);
					}
					catch (bad_cast&) {
						cout << "Bad cast" << endl;
					}

				}
			}

		}

		time = clockTransformation.getElapsedTime();

		if (time + addedTime > timeBetweenTransformations && !isPlaying && !isEating && tamaVector[tamagotchiCount - 1]->getExperience() > 300) {
			Tamagotchi *tamagotchi;
			addedTime = sf::seconds(0);
			if (typeid(Egg) == typeid(*tamaVector[tamagotchiCount - 1])) {
				Egg &egg = dynamic_cast<Egg &>(*tamaVector[tamagotchiCount - 1]);
				tamagotchi = new Chicken(egg);
			}
			else if (typeid(Chicken) == typeid(*tamaVector[tamagotchiCount - 1])) {
				Chicken &chicken = dynamic_cast<Chicken &>(*tamaVector[tamagotchiCount - 1]);
				tamagotchi = new Dragon(chicken);

			}
			tamaVector.push_back(tamagotchi);
			tamagotchiCount++;
			clockTransformation.restart();
			timeBetweenTransformations = sf::seconds(1.5 * timeBetweenTransformations.asSeconds());
		}

		time = clockGrowingUp.getElapsedTime();

		if (time > timeToGrowUp && !isPlaying && !isEating) {
			tamaVector[tamagotchiCount - 1]->loseHappiness();
			tamaVector[tamagotchiCount - 1]->getHungry();
			clockGrowingUp.restart();
		}

		if (time > timeBetweenFood && isEating &&!isPlaying) {
			int x = rand() % 500;
			Fruit *tmp = new Fruit(x, 0);
			fruits.push_back(tmp);
			clockObjectGenerator.restart();
			fruitCounter++;
			if (fruitCounter > 15) {
				isEating = false;
				fruitCounter = 0;
			}
		}
		time = clockObjectGenerator.getElapsedTime();
		if (time > timeBetweenBalls && isPlaying && !isEating) {
			int x = rand() % 500;
			Ball *tmp = new Ball(x, 0);
			balls.push_back(tmp);
			clockObjectGenerator.restart();
			ballsCounter++;
			if (ballsCounter > 20) {
				isPlaying = false;
				ballsCounter = 0;
			}
		}
		//jesli zaniedbamy tamagotchi to.... [*]
		if ((tamaVector[tamagotchiCount - 1]->getHunger() >= 100)||  (tamaVector[tamagotchiCount - 1]->getHappiness() <= 10))
			return 0;

		for (int i = 0; i < fruits.size(); i++) {
			if (fruits[i]->returny() < 330) {
				fruits[i]->move(14);
				fruits[i]->draw(window);
			}

			GameObject *object = (dynamic_cast<GameObject*>(tamaVector[tamagotchiCount - 1]));
			if (fruits[i]->returny() + 20 > object->returny() && fruits[i]->returny() < object->returny()
				&& (fruits[i]->returnx() < object->returnx() + 100) && fruits[i]->returnx() > object->returnx()) {
				tamaVector[tamagotchiCount - 1]->feed();
				delete fruits[i];
				fruits.erase(fruits.begin() + i, fruits.begin() + i + 1);
			}
		}

		for (int i = 0; i < balls.size(); i++) {
			if (balls[i]->returny() < 330) {
				balls[i]->move(24);
				balls[i]->draw(window);
			}
			
			GameObject *object = (dynamic_cast<GameObject*>(tamaVector[tamagotchiCount - 1]));
			if (balls[i]->returny() + 20 > object->returny() && balls[i]->returny() < object->returny()
				&& (balls[i]->returnx() < object->returnx() + 100) && balls[i]->returnx() > object->returnx()) {
				tamaVector[tamagotchiCount - 1]->play();
				delete balls[i];
				balls.erase(balls.begin() + i, balls.begin() + i + 1);
			}
		}

		show_info(window);
		window.display();
		window.clear();

	}
	return 0;
}

void Game::show_info(sf::RenderWindow &window)
{

	int tamaHunger = tamaVector[tamagotchiCount - 1]->getHunger();
	int tamaHappiness = tamaVector[tamagotchiCount - 1]->getHappiness();
	int tamaExperience = tamaVector[tamagotchiCount - 1]->getExperience();

	text_happiness.setString(int2str(tamaHappiness));
	text_hunger.setString(int2str(tamaHunger));
	text_experience.setString(int2str(tamaExperience));



	window.draw(title_happiness);
	window.draw(title_hunger);
	window.draw(title_experience);

	window.draw(text_happiness);
	window.draw(text_hunger);
	window.draw(text_experience);
	window.draw(text_play);
	window.draw(text_feed);


	window.draw(rectangle_up);
	window.draw(bottom_line);


	tamaVector[tamagotchiCount - 1]->draw(window);
}