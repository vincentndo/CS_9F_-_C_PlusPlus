#ifndef AMOEBA_H
#define AMOEBA_H

#include <string>

using namespace std;

class Amoeba {
public:
	Amoeba (string);		// birth of an amoeba
	string Name ();			// returns your name
	Amoeba* Parent ();		// returns your parent
	void AddChild (Amoeba*);	// add a baby amoeba to the family
	void PrintChildren();
	void PrintGrandchildren();
	void PrintDescendants();
private:
	string myName;	
	//Amoeba* myName;		// this amoeba's name
	Amoeba* myParent;		// good old mom (or is it dad?)
	Amoeba* myOlderSibling;		// the next older brother/sister
	Amoeba* myYoungestChild;	// the youngest kid
	Amoeba* myOldestChild;		// the oldest kid
};

#endif
