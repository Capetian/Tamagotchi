#ifndef MY_EXCEPTION_H_
#define MY_EXCEPTION_H_

#include <sstream>
#include <string>
#include <iostream>

using namespace std;

//klasa do obslugi wyjatkow
class MyException
{
protected:
	string message;
public:
	MyException();
	void show_message();
};

//wyjatek nieudanego wczytania stanu gry z pliku
class UnloadedGame : public MyException{
public:
	UnloadedGame();
};

#endif