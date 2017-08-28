#include <iostream>
#include <cassert>
#include "dll.h"

using namespace std;

// Implementation of a circular doubly linked list.

DLLnode::DLLnode (int k) {
    myValue = k;
    myPrevious = myNext = this;   // start off with null links
	                          // that eventually will be replaced
}

// Return the successor of the given node.
// Precondition: this != 0.
DLLnode *DLLnode::Next () {
    assert (this != 0);
    assert (myPrevious != 0);  // consistency checks on circular list
    assert (myNext != 0);
    return myNext;
}

// Return the predecessor of the given node.
// Precondition: this != 0.
DLLnode *DLLnode::Previous () {
    assert (this != 0);
    assert (myPrevious != 0);     // consistency checks on circular list
    assert (myNext != 0);
    return myPrevious;
}

// Insert the node pointed to by ptr at the head of list
// and return a pointer to new element.
DLLnode *DLLnode::Insert (DLLnode *ptr) {
    // you fill this in

    //DLLnode* temp=this;

    //myValue = ptr->myValue;
    if (this != 0)
    {
        ptr->myNext = this;
        ptr->myPrevious = this->myPrevious;
        (this->myPrevious) -> myNext = ptr;
        this->myPrevious = ptr;
    }
    //this = ptr;

    return ptr;
}

// Delete the first node from the list and return pointer to its
// successor, or 0 if there was only one element in the list to
// start with. Precondition: this != 0.
DLLnode *DLLnode::Delete () {
    // you fill this in
    assert (this != 0);
    cout << "Deleting node " << myValue << endl;

    //DLLnode* temp = this;

    (this->myPrevious)->myNext = this->myNext;
    (this->myNext)->myPrevious = this->myPrevious;
    DLLnode* temp = this->myNext;
    myValue = 0;
    myPrevious = 0;
    myNext = 0;    

    return temp;
}

// Print the list.
void DLLnode::Print () {
    if (this != 0) {
	DLLnode *temp = this;
	do {
	    cout << temp->myValue << " ";
	    temp = temp->myNext;
	} while (temp != this);
    }
    cout << endl;
}

// Return true if the list contains exactly 1 element.
bool DLLnode::LengthIs1 () {
    if (this == 0) {
	return false;
    } else if (this == myPrevious) {
	assert (myNext == myPrevious);    // consistency check on 1-elem list
	return true;
    } else if (this == myNext) {
	assert (false);               // failed consistency check!
    } else {
	return false;
    }
}

