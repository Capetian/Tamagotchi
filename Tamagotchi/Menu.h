#ifndef MENU_H_
#define MENU_H_
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Buttons.h"
#include "Game.h"

class Main_Menu
{
protected:
	vector<Button*> button;
	Button *p_b;
	Font font;
	sf::Text text;
public:
	Main_Menu();
	Main_Menu(string name);
	~Main_Menu();
	//metoda oblsugujaca glowne menu gry
	int main_menu(sf::RenderWindow &window);
	//metoda przyjmujaca wybrana pozycje w menu i zwracajaca wynik wybranej funkcji
	int selected_position(int p, sf::RenderWindow &window);
};

void startGame(sf::RenderWindow &window, bool loaded);

/*
class Pause : public Main_Menu
{
public:
	Pause();
	int pause_menu(sf::RenderWindow &window, Player &player);
	int selected_position(int p, sf::RenderWindow &window, Player &player);
};

//funkcja obslugujaca wybranie przycisku nowej gry
//void start_new_game(sf::RenderWindow &window);

//funkcja obslugujaca wybranie przycisku zaladowanej gry
//void start_loaded_game(sf::RenderWindow &window);
*/

class Pause : public Main_Menu
{
public:
	Pause();
	~Pause();
	int pause_menu(sf::RenderWindow &window, Tamagotchi *tamagotchi, sf::Time time);
	int selected_position(int p, sf::RenderWindow &window, Tamagotchi *tamagotchi, sf::Time time);

};
#endif