#include <iostream>
#include "amoebas.h"

using namespace std;

Amoeba::Amoeba (string s) {	// an amoeba is born, named s
	myName = s;
	myParent = 0;
	myOlderSibling = 0;
	myOldestChild = 0;
	myYoungestChild = 0;
}

// Access functions
string Amoeba::Name () {
	return myName;
}

Amoeba* Amoeba::Parent () {
	return myParent;
}

void Amoeba::AddChild (Amoeba* newChild) {
	// make child point to parent
	newChild->myParent = this;

	// check for parent having other children
	Amoeba* otherSibling = myYoungestChild;
	if (!otherSibling) {	// the new amoeba is an only child
		myYoungestChild = newChild;	// make the parent's child
		myOldestChild = newChild;		// ptrs point to the new one
		newChild->myOlderSibling = 0;	// no older sibling
	} else {	// there are other kids; make this one the youngest
		myYoungestChild = newChild;	// no younger siblings,
		newChild->myOlderSibling = otherSibling;	// but new kid now
	}					// has older siblings.
}

void Amoeba::PrintChildren()
{
	if (this->myYoungestChild ==0)
	{
		cout << "I have no child." << endl;
	}
	else
	{
		cout << myYoungestChild->myName << endl;

		Amoeba *temp = myYoungestChild->myOlderSibling;
		
		while (temp)    // not *temp != 0
		{
			cout << temp->myName << endl;
			temp = temp->myOlderSibling;			
		}
	}
}


void Amoeba::PrintGrandchildren()
{
	int count = 0;

	if (myYoungestChild ==0)
	{
		cout << "I have no grandchildren." << endl;
	}
	else
	{		
		Amoeba *temp = myYoungestChild;
				
		while (temp)    // not *temp != 0
		{
			if (temp->myYoungestChild)
			{
				temp->PrintChildren();
				count ++;
			}
			
			// Amoeba *temp2 = temp->myYoungestChild->myOlderSibling;
			
			// 	while (temp2)
			// 	{
			// 		cout << temp2->myName << endl;
			// 		count++;
			// 		temp2 = temp2->myOlderSibling;
			// 	}
			temp = temp->myOlderSibling;				
		}
	}

	if (!count)
	{
		cout << "I have no grandchildren" << endl;
	}
}


void Amoeba::PrintDescendants()
{
	if (myYoungestChild ==0)
	{
		cout << "I have no grandchildren." << endl;
	}
	else
	{
		Amoeba *temp = myYoungestChild;


		while (temp)
		{
			cout << temp->myName << endl;
			Amoeba * temp2 = temp->myYoungestChild;
			while (temp2)
			{
				cout << "    " << temp2->myName << endl;
				Amoeba * temp3 = temp2->myYoungestChild;
				while (temp3)
				{
					cout << "        " << temp3->myName << endl;
					temp3 = temp3->myOlderSibling;
				}
				temp2 = temp2->myOlderSibling;
			}
			temp = temp->myOlderSibling;
		}
	}
}