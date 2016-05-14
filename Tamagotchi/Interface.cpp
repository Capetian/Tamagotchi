#include "stdafx.h"
#include "Interface.h"



string int2str(int i)
{
	stringstream ss;
	string temp;
	ss << i;
	ss >> temp;
	return temp;
}

Font::Font()
{
	if (!style.loadFromFile("tamagotchi.ttf"))
	{
		cout << "error" << endl;
	}
}
