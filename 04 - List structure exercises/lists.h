#ifndef _LISTS_H
#define _LISTS_H

class ListNode {
public:
	ListNode (int k);
	ListNode (int k, ListNode* ptr);
	~ListNode ();       // delete the node and all nodes
                       // accessible through it;
                       // precondition: this != 0.
	int First ();       // return the value stored in the list node
	ListNode *Rest ();  // return the list consisting of
                       // the remaining elements
	void Print ();      // print the list
private:
	int myValue;
	ListNode* myNext;
};
#endif
