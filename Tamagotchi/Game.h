#ifndef GAME_H_
#define GAME_H_
#include "stdafx.h"

class Game {
public:

	Game(bool loaded);
	~Game();
	int play(sf::RenderWindow &window);
	void show_info(sf::RenderWindow &window);
	sf::Time time;
	sf::Time t1;
	sf::Time t2;
	sf::Time t3;
	sf::Clock clockTransformation;
	sf::Clock clockObjectGenerator;
	sf::Clock clockGrowingUp;
private:
	sf::Text text_play;
	sf::Text text_feed;


	sf::Text text_hunger;
	sf::Text text_experience;
	sf::Text text_happiness;


	sf::Text title_hunger;
	sf::Text title_experience;
	sf::Text title_happiness;


	sf::RectangleShape rectangle_up;

	Font font;
	Font font_numb;
	int tamagotchiCount;
	bool isPlaying = false;
	bool isEating = false;
	int fruitCounter = 0;
	int ballsCounter = 0;
	vector <Fruit*> fruits;
	vector <Ball*> balls;
	vector <Tamagotchi*> tamaVector;
};
#endif
