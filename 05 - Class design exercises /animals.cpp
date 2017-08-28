#include <iostream>
#include <string>
#include "positions.h"
#include "animals.h"

using namespace std;

Mouse::Mouse(string s, Position p): Animal(s,p)
{
    myName = s;
    myPos = p;
    myTarget =0;
}

bool Mouse::Chase()
{
	cout << "Mouse doesn't chase. Mouse just moves around"<<endl;
    myPos.IncrementPosition(0,1.);
    return 0;
}


Cat::Cat(string s, Position p): Animal(s,p)
{
    myName = s;
    myPos = p;
    myTarget = 0;
}

bool Cat::Chase()
{
	//int count=0;

    Position cat_next;
    cat_next.SetAbsolutePosition(myPos.Rad(),myPos.Ang());
    cat_next.IncrementPosition(0,1.25);

    if ((myTarget->Pos()).IsBetween(myPos,cat_next) == 0)
    {
    	//count += 1;
        
    	if (myPos.IsAtStatue() == 0)
    	{
            if (myPos.Sees(myTarget->Pos()) == 0)
    		{
                myPos.IncrementPosition(0,1.25);
    			//cout<< "TIME"<< count<< endl;
                cout << "\tCat doesn't see its target. Go around:" << endl;
    			cout<< "\tCat.";
    			myPos.Print();    			
    		}
    		else
    		{
    			myPos.IncrementPosition(-1,0);
                //cout<< "TIME"<< count<< endl;
                cout << "\tCat sees its target. Jump:" << endl;        
                cout<< "\tCat.";
                myPos.Print();
    		}
    	}
    	else
    	{
    		myPos.IncrementPosition(0,1.25);            
            //cout<< "TIME"<< count<< endl;
            cout << "\tAt Statue. Chase:" << endl;
            cout<< "\tCat.";
            myPos.Print();
    	}
    	(myTarget->Pos()).IncrementPosition(0,1);
        cout<< "\tMouse.";
        (myTarget->Pos()).Print();
        cat_next.SetAbsolutePosition(myPos.Rad(),myPos.Ang());
        cat_next.IncrementPosition(0,1.25);
        return 0;
    }
    else
    {
        cout << "Hooray! Cat catches its target!" << endl;
        return 1;
    }
}


Person::Person(string s, Position p): Animal(s,p)
{
    myName = s;
    myPos = p;
    myTarget = 0;
}

bool Person::Chase()
{
	bool ret = 0;
	if ( ((myTarget->Pos()).Rad()==1) && (myPos.Sees(myTarget->Pos())) )
	{
        cout << "Person saw its target at statue, and took a photo of it." << endl;		
	}
	else
	{
        cout << "Person didn't its target at statue, couldn't take a photo of it. " << endl;		
	}
    myPos.IncrementPosition(0,-2.);
    return ret;
}