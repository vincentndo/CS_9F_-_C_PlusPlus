#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
#include <cassert>

using namespace std;

template <class NODETYPE> class SortedList;
template <class NODETYPE> class SortedListIterator;

template <class NODETYPE>
class ListNode {
	friend class SortedList<NODETYPE>;
	friend class SortedListIterator<NODETYPE>;
public:
	ListNode (const NODETYPE &);
	NODETYPE Info ();
private:
	NODETYPE myInfo;
	ListNode* myNext;
};

template <class NODETYPE>
ListNode<NODETYPE>::ListNode (const NODETYPE &value) {
	myInfo = value;
	myNext = 0;
}

template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::Info () {
	return myInfo;
}

template <class NODETYPE>
class SortedList {
	friend class SortedListIterator<NODETYPE>;
public:
	SortedList ();
	~SortedList ();
	SortedList (const SortedList <NODETYPE> &);
	void Insert (const NODETYPE &);
	bool IsEmpty ();
	SortedList<NODETYPE>& operator = (const SortedList<NODETYPE> & list);
private:
	ListNode <NODETYPE>* myFirst;
};

template <class NODETYPE>
SortedList<NODETYPE>::SortedList() {	// constructor
	myFirst = 0;
}

template <class NODETYPE>
SortedList<NODETYPE>::~SortedList() {	// destructor
	if (!IsEmpty ()) {
		cerr << "*** in destructor, destroying: ";
		ListNode <NODETYPE>* current = myFirst;
		ListNode <NODETYPE>* temp;
		while (current != 0) {
			cerr << " " << current->myInfo;
			temp = current;
			current = current->myNext;
			delete temp;
		}
		cerr << endl;
	} //cout<< "done"<<endl;
}

template <class NODETYPE>
SortedList<NODETYPE>::SortedList(const SortedList <NODETYPE> & list) {	// copy constructor
	cerr << "*** in copy constructor" << endl;
	ListNode <NODETYPE>* listCurrent = list.myFirst;
	ListNode <NODETYPE>* newCurrent = 0;
	while (listCurrent != 0) {
		ListNode <NODETYPE> *temp 
		  = new ListNode <NODETYPE> (listCurrent->Info ());
		if (newCurrent == 0) {
			myFirst = temp;
			newCurrent = myFirst;
		} else {
			newCurrent->myNext = temp;
			newCurrent = temp;
		}
		listCurrent = listCurrent->myNext;
	}
}

template <class NODETYPE>
void SortedList<NODETYPE>::Insert(const NODETYPE & value) {	// Insert
	ListNode <NODETYPE> *toInsert 
	  = new ListNode <NODETYPE> (value);
	if (IsEmpty ()) {
		myFirst = toInsert;
	} else if (value < myFirst->Info ()) {
		toInsert->myNext = myFirst;
		myFirst = toInsert;
	} else {
		ListNode <NODETYPE> *temp = myFirst;
		for (temp = myFirst; 
			  temp->myNext != 0 && temp->myNext->Info () < value; 
			  temp = temp->myNext) {
		}
		toInsert->myNext = temp->myNext;
		temp->myNext = toInsert;
	}
}

template <class NODETYPE>
bool SortedList<NODETYPE>::IsEmpty() {	// IsEmpty
	return myFirst == 0;
}


template <class NODETYPE>
SortedList <NODETYPE>& SortedList<NODETYPE>::operator = (const SortedList <NODETYPE> & list)
{
	cout << "Stop here 1" << endl;
	delete this;       // question	
	cout << "Stop here 2" << endl;
	
	if (this == & list )
	{
		cerr << "Assigning to myself"<<endl;
		return *this;
	}



	// ListNode<NODETYPE> * temp;
	// while (myFirst)
	// {
	// 	temp = myFirst;
	// 	myFirst = myFirst->myNext;
	// 	delete temp;
		
	// }
	//cout<< "my first is: "<< myFirst->Info()<<endl;

	// ListNode<NODETYPE> * temp=myFirst;
	// while (!temp)
	// {
	//	myFirst = myFirst->myNext;
	// 	delete temp;
	// 	temp = myFirst;
	// }

	// ListNode<NODETYPE> * temp=myFirst;
	// while (!temp)
	// {
	// 	delete temp;
	// 	temp = myFirst->myNext;
	// }

	ListNode <NODETYPE>* current = myFirst;
	ListNode <NODETYPE>* temp;
	while (current != 0) {
		cerr << " " << current->myInfo;
		temp = current;
		current = current->myNext;
		delete temp;
	}
	cout << " my first next is : "<< myFirst->myNext->Info() << endl;

	SortedList<NODETYPE> * newlist_ptr = new SortedList<NODETYPE>(list);
	myFirst = newlist_ptr->myFirst;

	return *this;
}


// SortedListIterator class

template <class NODETYPE>
class SortedListIterator {
public:
	SortedListIterator();
	SortedListIterator(const SortedList<NODETYPE> & list);
	bool MoreRemain();
	NODETYPE Next();
private:
	ListNode <NODETYPE>* myNode;
};

template <class NODETYPE>
SortedListIterator<NODETYPE>::SortedListIterator()
{
	myNode = 0;
}

template <class NODETYPE>
SortedListIterator<NODETYPE>::SortedListIterator(const SortedList<NODETYPE> & list)
{
	SortedList<NODETYPE> * newlist_ptr = new SortedList<NODETYPE> (list);
	myNode = newlist_ptr->myFirst;
}

template <class NODETYPE>
bool SortedListIterator<NODETYPE>::MoreRemain()
{
	bool ret = 0;
	if (myNode)
	{
		ret = 1;
		return ret;
	}
	else
	{
		return ret;
	}
}

template <class NODETYPE>
NODETYPE SortedListIterator<NODETYPE>::Next()
{
	NODETYPE temp = myNode->Info();
	myNode = myNode->myNext;
	return temp;
}

#endif