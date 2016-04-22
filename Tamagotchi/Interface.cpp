#include "stdafx.h"
#include "Interface.h"
#include <iostream>


Font::Font()
{
	if (!style.loadFromFile("tamagotchi.ttf"))
	{
		cout << "error" << endl;
	}
}
