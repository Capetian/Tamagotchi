#include "stdafx.h"
#include "Files.h"

void save_game(Tamagotchi *tamagotchi)
{
	ofstream fout(SAVE);
	if (!fout.is_open())
	{
		fout.clear();
		return;
	}
	//wykorzystanie przeciazonego operatora <<
	fout << tamagotchi;
	fout.close();
}

AbstractObject getTamagotchiFromFile() {
	ifstream fin(SAVE);
	AbstractObject object = AbstractObject();
	if (!fin.is_open()) {
		fin.clear(); // zeruje stan strumienia
		return object; //jezeli plik nie istnial, funkcja zwraca 'pustego' gracza
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
			//wczytanie z pliku nie powiodlo sie, zwracany jest 'pusty' gracz
		}

		fin.close();
		return object;
		//wszystko wczytalo sie poprawnie, zwracany jest gracz z wczytanymi wartosciami
	}
}

//Player load_game()
//{
//	ifstream fin(SAVE);
//	if (!fin.is_open())
//	{
//		fin.clear(); // zeruje stan strumienia
//		Player player;
//		return player; //jezeli plik nie istnial, funkcja zwraca 'pustego' gracza
//	}
//	else
//	{
//		Player player;
//		//wykorzystanie przeciazonego operatora >>
//		try
//		{
//			fin >> player;
//		}
//		catch (UnloadedGame &e)
//		{
//			e.show_message();
//			fin.close();
//			return player;
//			//wczytanie z pliku nie powiodlo sie, zwracany jest 'pusty' gracz
//		}
//
//		fin.close();
//		return player;
//		//wszystko wczytalo sie poprawnie, zwracany jest gracz z wczytanymi wartosciami
//	}
//}
