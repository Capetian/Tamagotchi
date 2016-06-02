#ifndef ABSTRACT_OBJECT_H_
#define ABSTRACT_OBJECT_H_
#include "stdafx.h"

class AbstractObject {
public:
	AbstractObject();
	int happiness;
	int type;
	int hunger;
	int experience;


	friend istream& operator>>(istream &in, AbstractObject &object);
};

#endif