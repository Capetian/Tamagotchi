#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include "stdafx.h"
class GameObject
{
protected:
	//pola przechowujace informacje o wspolrzednych obiektu
	float x;
	float y;

public:
	//konstruktor bezargumentowy
	GameObject() {};

	//konstruktor przyjmujacy jako argumenty poczatkowe wspolrzedne obiektu
	GameObject(float _x, float _y) : x(_x), y(_y) {};

	//metoda zwracajaca wspolrzedna x aktualnego polozenia
	float returnx();

	//metoda zwracajaca wspolrzedna y aktualnego polozenia
	float returny();

};

#endif