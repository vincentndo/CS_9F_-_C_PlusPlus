#ifndef _ANIMALS_H
#define _ANIMALS_H

#include <iostream>
#include <string>
#include "positions.h"
#include "park.h"

using namespace std;

class Mouse: public Animal{
public:
	Mouse();
	Mouse(string s, Position p);
	bool Chase();
};

class Cat: public Animal{
public:
	Cat();
	Cat(string s, Position p);
	bool Chase();
};

class Person: public Animal{
public:
	Person();
	Person(string s, Position p);
	bool Chase();
};

#endif