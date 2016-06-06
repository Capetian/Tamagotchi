#include "stdafx.h"
#include "Files.h"

void save_game(Tamagotchi *tamagotchi, sf::Time time)
{
	ofstream fout(SAVE);
	if (!fout.is_open())
	{
		fout.clear();
		return;
	}
	//wykorzystanie przeciazonego operatora <<
	fout << tamagotchi;
	fout << time.asSeconds();
	fout.close();
	cout << "Zapisano gre!" << endl;
}

GameState getTamagotchiFromFile() {
	ifstream fin(SAVE);
	GameState object = GameState();
	if (!fin.is_open()) {
		fin.clear(); // zeruje stan strumienia
		return object; //jezeli plik nie istnial, funkcja zwraca 'pusty' stan gry
	}
	else {
	
		//wykorzystanie przeciazonego operatora >>
		try
		{
			fin >> object;
		}
		catch (UnloadedGame &e)
		{
			e.show_message();
			fin.close();
			return object;
			//wczytanie z pliku nie powiodlo sie, zwracany jest 'pusty' obiekt stanu gry
		}

		fin.close();
		cout << "Poprawnie wczytano stan gry" << endl;
		return object;
		//wszystko wczytalo sie poprawnie, zwracany jest stan gry z wczytanymi wartosciami
	}
}

