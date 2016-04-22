#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

using namespace std;

#ifndef INTERFACE_H_
#define INTERFACE_H_



//klasa przechowujaca wczytana z pliku czcionke
class Font {
public:
	//publiczne pole obiektu klasy z biblioteki sfml aby umozliwic bezposrednie korzystanie z metod tej klasy
	sf::Font style;

	//konstruktor bezargumentowy
	Font();
};

#endif