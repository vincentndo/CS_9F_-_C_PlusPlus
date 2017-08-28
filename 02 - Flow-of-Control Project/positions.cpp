#include <iostream>
#include <cmath>
#include "positions.h"
using namespace std;

Position::Position ()
{

}

Position::Position (float r)
{
	myRadius = r;
}

Position::Position (float r, float thetaInRadians)
{
	myRadius = r;
	myAngleInRadians = thetaInRadians;
}

void Position::SetAbsolutePosition (float r, float thetaInRadians)
{
	myRadius = r;
	myAngleInRadians = thetaInRadians;
}

void Position::IncrementPosition (float rChange, float angularDistChange)
{
	if ((myRadius+rChange)<1)
	{
		myRadius = 1;
	}
	else
	{
		myRadius += rChange;
	}
	
	myAngleInRadians += angularDistChange/myRadius;
}

void Position::Print ( )
{
	cout << "Position: Radius " << myRadius << ", Angle " << myAngleInRadians << endl;
}

bool Position::Sees (Position pos)
{
	bool ret = true;

	if (myRadius*cos(myAngleInRadians - pos.Ang() ) >= 1)
	{
		return ret;
	}
	else
	{
		ret = false;
		return ret;
	}
}

bool Position::IsAtStatue ( )
{
	bool ret = true;

	if (myRadius == 1)
	{
		return ret;
	}
	else
	{
		ret = false;
		return ret;
	}
}

bool Position::IsBetween (Position pos1, Position pos2)
{
	bool ret = false;

	if (((pos1.Ang() - pos2.Ang())>=3.14) ||
		(pos1.Rad() != myRadius) || (pos2.Rad() !=myRadius))
	{
		return ret;
	}
	else
	{
		if ((cos(myAngleInRadians - pos1.Ang()) > cos(pos2.Ang() - pos1.Ang()))
			&& (cos(pos2.Ang() - myAngleInRadians) > cos(pos2.Ang()-pos1.Ang())))
		{
			ret = true;
			return ret;
		}
		else
		{
			return ret;
		}
	}
}

float Position::Rad()
{
	return myRadius;
}

float Position::Ang()
{
	return myAngleInRadians;
}