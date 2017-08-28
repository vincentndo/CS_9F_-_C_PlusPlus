#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

void InterpretCommands (istream&);
void InterpretUpdate (istream&);
void InterpretList (istream&);
void InterpretBatch (istream&);
void InterpretQuit (istream&);

void InterpretCommands (istream& cmds) {
  string line, lineInWord;
  while ( getline(cmds, line) ) {
    istringstream lineIn (line.c_str());
    if ( !(lineIn >> lineInWord) ) {
      cout << "Blank line." << endl ;
    } else if (lineInWord=="update") {
      InterpretUpdate (lineIn);
    } else if (lineInWord=="list") {
      InterpretList (lineIn);
    } else if (lineInWord=="batch") {
      InterpretBatch (lineIn);
    } else if (lineInWord=="quit") {
      InterpretQuit (lineIn);
    } else { 
      cerr << "Unrecognizable command word." << endl; 
    }
  }
}

int main ( ) {
  InterpretCommands (cin);
  return 0;
}

void InterpretUpdate (istream & lineIn)
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
		}
	}
	else
	{
		cout << "Not a correct 'update' command." << endl;
	}
}

void InterpretList (istream & lineIn)
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
		}		
	}
	else
	{
		cout << "Not a correct 'list' command." << endl;
	}	
}

void InterpretBatch (istream & lineIn)
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

			InterpretCommands(input);
			InterpretCommands(cin);
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