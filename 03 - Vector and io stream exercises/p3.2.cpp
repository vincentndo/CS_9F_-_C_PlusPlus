#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "inventory.h"

using namespace std;

void InterpretCommands (istream&, Inventory&);
void InterpretUpdate (istream&, Inventory&);
void InterpretList (istream&, Inventory&);
void InterpretBatch (istream&, Inventory &);
void InterpretQuit (istream&);

void InterpretCommands (istream& cmds, Inventory & store) {
  string line, lineInWord;
  while ( getline(cmds, line) ) {
    istringstream lineIn (line.c_str());
    if ( !(lineIn >> lineInWord) ) {
      cout << "Blank line." << endl ;
    } else if (lineInWord=="update") {
      InterpretUpdate (lineIn, store);
    } else if (lineInWord=="list") {
      InterpretList (lineIn, store);
    } else if (lineInWord=="batch") {
      InterpretBatch (lineIn, store);
    } else if (lineInWord=="quit") {
      InterpretQuit (lineIn);
    } else { 
      cerr << "Unrecognizable command word." << endl; 
    }
  }
}

int main ( ) {
	// string inventory_name;

	// cout << "Enter inventory name: ";
	// cin >> inventory_name;
	// cout << endl;
	Inventory store;
	// vector <Inventory> stores
	// for userinput:
	// 	Inventory temp = new Inventory
	// 	stores.push_back
  InterpretCommands (cin, store);
  return 0;
}

void InterpretUpdate (istream & lineIn, Inventory & store)
{
	string s2, r;
	int n1;

	if (lineIn >> s2 >> n1)
	{
		if (lineIn >> r)
		{
			cout << "Not a standard 'update' command." << endl;
		}
		else
		{
			cout << "Command: update" <<". Argument: " << s2 << ", " << n1<< endl;
			store.Update(s2,n1);
		}
	}
	else
	{
		cout << "Not a correct 'update' command." << endl;
	}

}

void InterpretList (istream & lineIn, Inventory & store)
{
	string s2, r;

	lineIn >> s2;

	if ( (s2=="names") || (s2=="quantities") )
	{
		if (lineIn >> r)
		{
			cout << "Not a standard 'list' command." << endl;
		}
		else
		{
			cout << "Command: list" <<". Argument: " << s2 << endl;
			if (s2 == "names")
			{
				store.ListByName();
			}
			else if (s2 == "quantities")
			{
				store.ListByQuantity();
			}
		}		
	}
	else
	{
		cout << "Not a correct 'list' command." << endl;
	}	
}

void InterpretBatch (istream & lineIn, Inventory & store)
{
	ifstream input;
	string filename, r;

	if (lineIn >> filename)
	{
		if (lineIn >> r)
		{
			cout << "Not a standard 'batch' command." << endl;
		}
		else
		{
			input.open(filename.c_str());

			if (!input)
			{
				cout << "could not open " << filename<< endl;
				exit(1);
			}

			InterpretCommands(input, store);
			InterpretCommands(cin, store);
		}		
	}
	else
	{
		cout << "Not a correct 'batch' command." << endl;
	}

	

	// while (getline(input,s))
	// {
	// 	istringstream lineIn(s);
	// 	if (lineIn >> lineInWord)
	// 	{
	// 		________ ;
	// 	}
 //    	else if (lineInWord=="update")
 //    	{
 //     		InterpretUpdate (lineIn);
 //    	}
 //    	else if (lineInWord=="list")
 //    	{
 //    		InterpretList (lineIn);
	// 	}
	// 	else
	// 	{
	// 		cerr << "Unrecognizable command word." << endl;
	// 	}
	// }

	//getline(cin, s);
	
}

void InterpretQuit (istream & lineIn)
{
	string r;

	if (lineIn >> r)
	{
		cout << "Not a standard 'batch' command." << endl;
	}
	else
	{
		exit(1);
	}
}