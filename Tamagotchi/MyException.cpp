#include "stdafx.h"
#include "MyException.h"

MyException::MyException(){
	message = "Nieznany blad";
}

void MyException::show_message(){
	cout << message << endl;
}

UnloadedGame::UnloadedGame(){
	message = "Blad wczytania stanu gry z pliku";
}

