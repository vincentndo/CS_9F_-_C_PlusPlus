#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#define M 19
#define N 19

using namespace std;

class ChessBoard{
public:
	ChessBoard();
	void SetCell (int player, int row, int col, char c);
	void Print (int player);
private:
	vector< vector<char> > cell;
};

int main(){
	ChessBoard test;
	test.Print(0);

	string line;
	int player, row, col;
	char c;

	cout << "Enter player, row, col, c to set a cell: ";

	while (getline(cin, line))
	{
		if (line == "done")
		{
			cout << "Player: me" << endl;
			test.Print(0);
			cout << "Player: opposite" << endl;
			test.Print(1);
			return 0;
		}
		else
		{
			istringstream lineIn (line.c_str());
			if (lineIn >> player >> row >> col >> c)
			{
				test.SetCell(player,row,col,c);
				cout << "Enter player, row, col, c to set a cell: ";
			}
			else
			{
				cout << "Invalid parameters. /* int player, 0<row<20, 0<col<20; char c */ " << endl;
				cout << "Enter player, row, col, c to set a cell: ";
			}
		}
	}
	return 0;
}

ChessBoard::ChessBoard()
	: cell(19, vector<char>(19) )
{
	int m = cell.size(), n = cell[0].size();

	for (int i = 0; i<m; i++)
	{
		for (int j=0; j<n; j++)
		{
			cell[i][j]='.';
		}
	}
}

void ChessBoard::SetCell(int player, int row, int col, char c)
{
	int m = cell.size(), n = cell[0].size();

	if ((row <20) && (row > 0) &&  (col < 20) && (col > 0))
	{
		if (player == 0)
		{
			cell[row-1][col-1] = c;
		}
		else if (player == 1)
		{
			cell[m-row][m-col] = c;
		}
		else
		{
			cout << "There is no such player!" << endl;
		}
	}
	else
	{
		cout << "Row and col must be less than 20" << endl;
	}
	
}

void ChessBoard::Print(int player)
{
	int m = cell.size(), n = cell[0].size();

	if (player == 0)
	{
		int m = cell.size(), n = cell[0].size();

		for (int i = 0; i<m; i++)
		{
			cout << "\t";
			for (int j=0; j<n; j++)
			{
				cout << cell[i][j] << " ";
			}
			cout << endl;
		}
	}
	else if (player = 1)
	{
		for (int i = m-1; i>=0; i--)
		{
			cout << "\t";
			for (int j=n-1; j>=0; j--)
			{
				cout << cell[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "There is no such player!" << endl;
	}
}