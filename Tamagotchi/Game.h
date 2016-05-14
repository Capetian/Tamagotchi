#ifndef GAME_H_
#define GAME_H_
#include "stdafx.h"

class Game {
public:
	Game();
	Game(bool loaded);
	int play(sf::RenderWindow &window);
	void show_info(sf::RenderWindow &window);
	sf::Time time;
	sf::Time t1;
	sf::Time t2;
	sf::Clock clock;
	sf::Clock clock_PU;
private:
	sf::Text text_play;
	sf::Text text_feed;
	sf::Text text_clean;
	sf::Text text_health;
	sf::Text title_health;
	sf::Text text_happiness;
	sf::Text title_happiness;
	sf::Text title_energy;
	sf::Text text_energy;
	sf::Text title_cleanless;
	sf::Text text_cleanless;
	sf::RectangleShape rectangle_up;
	sf::RectangleShape rectangle_down;
	Font font;
	int tamagotchiCount = 0;
	vector <Tamagotchi*> tamaVector;
	//Tamagotchi *tamagotchi;
};
#endif
