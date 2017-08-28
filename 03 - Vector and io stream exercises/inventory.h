#include <vector>
#include <string>

using namespace std;

class Inventory {
public:
	Inventory ();
	void Update (string item, int amount);
	void ListByName ();
	void ListByQuantity ();
private:
	// You provide this.

	struct stuff
	{
		string name;
		int quantity;
	};

	vector<stuff> DataBase;
	
};

Inventory::Inventory()
{
	DataBase.resize(0);
}

void Inventory::Update(string item, int amount)
{
	int n = DataBase.size();
	int exist = 0;

	for (int i=0; i<n; i++)
	{
		if (DataBase[i].name==item)
		{
			DataBase[i].quantity += amount;
			exist++;
		}	
	}

	if (!exist)
		{
			stuff newone;
			newone.name = item;
			newone.quantity = amount;

			DataBase.push_back(newone);
		}
}

void Inventory::ListByName()
{
	int n = DataBase.size(), m;
	stuff temp;

	for (int i=0; i<n; i++)
	{
		m = i;
		temp = DataBase[i];
		for ( int j=i;j<n;j++)
		{
			if (DataBase[j].name<temp.name)
			{
				temp = DataBase[j];
				m=j;
			}
		}
		DataBase[m] = DataBase[i];
		DataBase[i] = temp;
		cout << "\t" << i+1 << ". "<< temp.name << " " << temp.quantity <<endl; 
	}
}

void Inventory::ListByQuantity()
{
	int n = DataBase.size(), m;
	stuff temp;

	for (int i=0; i<n; i++)
	{
		m = i;
		temp = DataBase[i];
		for ( int j=i;j<n;j++)
		{
			if (DataBase[j].quantity<temp.quantity)
			{
				temp = DataBase[j];
				m=j;
			}
		}
		DataBase[m] = DataBase[i];
		DataBase[i] = temp;
		cout << "\t" << i+1 << ". "<< temp.quantity << " " << temp.name <<endl; 
	}
}