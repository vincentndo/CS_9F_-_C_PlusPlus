#include <iostream>
#include <cmath>
#include "positions.h"

using namespace std;

// You define the GetPositions function.
// It should read legal cat and mouse positions from the user
// and return the position values in its two arguments.
void GetPositions (Position& cat, Position& mouse) {
	float m, r, c;
	
	cout << "Enter mouse position (degree): ";
	cin >> m;
    mouse.SetAbsolutePosition(1,m*3.14/180);
	cout << "Enter cat position (radius): ";
	cin >> r;    
	cout << "Enter cat position (degree): ";
	cin >> c;
    cat.SetAbsolutePosition(r,c*3.14/180);
    
}

// You define the RunChase function.
// Given initialized cat and mouse positions,
// it should simulate the cat chasing the mouse, printing the 
// result of each movement of cat and mouse.  Either the cat will 
// catch the mouse, or 30 time units will go by and the cat will 
// give up.
void RunChase (Position & cat, Position & mouse) {
    
    int count=0;

    Position cat_next;
    cat_next.SetAbsolutePosition(cat.Rad(),cat.Ang());
    cat_next.IncrementPosition(0,1.25);

    while ((mouse.IsBetween(cat,cat_next) == 0) && (count < 30))
    {
    	count += 1;
        
    	if (cat.IsAtStatue() == 0)
    	{
            if (cat.Sees(mouse) == 0)
    		{
                cat.IncrementPosition(0,1.25);
    			cout<< "TIME"<< count<< endl;
                cout << "\tNo Sees. Go around:" << endl;
    			cout<< "\tCat.";
    			cat.Print();    			
    		}
    		else
    		{
    			cat.IncrementPosition(-1,0);
                cout<< "TIME"<< count<< endl;
                cout << "\tSees. Jump:" << endl;        
                cout<< "\tCat.";
                cat.Print();
    		}
    	}
    	else
    	{
    		cat.IncrementPosition(0,1.25);            
            cout<< "TIME"<< count<< endl;
            cout << "\tAt Statue. Chase:" << endl;
            cout<< "\tCat.";
            cat.Print();
    	}
    	mouse.IncrementPosition(0,1);
        cout<< "\tMouse.";
        mouse.Print();
        cat_next.SetAbsolutePosition(cat.Rad(),cat.Ang());
        cat_next.IncrementPosition(0,1.25);
    }

    if (count == 30)
    {
    	cout << "Cat cannot get mouse in 30mins." << endl;
    }
    else
    {
    	cout << "Hoora! Cat got mouse in " << count+1 << "mins." << endl;
    }
}

int main () {
    Position cat, mouse;
    GetPositions (cat, mouse);
    if (cat.Rad() < 1)
    {
        cout << "Invalid position of cat!"<< endl;
        return 0;
    }

    RunChase (cat, mouse);
    return 0;
}
