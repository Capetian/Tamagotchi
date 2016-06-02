#ifndef FILES_FUNCTIONS_H_
#define FILES_FUNCTIONS_H_
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

//stale dla nazw plikow

//nazwa pliku najlepszych wynikow
#define SCORES "scores.txt"
//nazwa pliku z zapisana gra
#define SAVE "save.txt"


////funkcja sortujaca dwie liczby w kolejnosci malejacej,
////zwraca true jezeli s1 jest wieksze od s2
//bool sortScores(const int &s1, const int &s2);
//
////funkcja wczytujaca z pliku najlepsze zapisane wyniki
////zwracajaca wypelniony wektor
//vector<int> load_top_scores(ifstream &fin);
//
////funkcja przyjmujaca i zapisujaca do pliku najlepszych wynikow wynik gracza po skonczonej rozgrywce
////zwraca true jezeli wynik zostal zapisany
//bool save_top_score(int score);
//
////funkcja wczytujaca z pliku liste najlepszych wynikow
////zwraca wektor liczb typu int
//vector<int> get_top_scores();

//funkcja zapisujaca do pliku aktualny stan rozgrywki
//przyjmuje referencje do obiektu Player
void save_game(Tamagotchi *tamagotchi);
AbstractObject getTamagotchiFromFile();

////funkcja wczytujaca z pliku uprzednio zapisany stan rozgrywki
////zwraca obiekt Player - gracza z uzupelnionymi polami o poziomie, wyniku i predkosci
//Player load_game();

#endif