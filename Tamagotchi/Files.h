#ifndef FILES_FUNCTIONS_H_
#define FILES_FUNCTIONS_H_
#include <fstream>
#include <iostream>

using namespace std;


//nazwa pliku z zapisana gra
#define SAVE "save.txt"

void save_game(Tamagotchi *tamagotchi, sf::Time time);
GameState getTamagotchiFromFile();


#endif