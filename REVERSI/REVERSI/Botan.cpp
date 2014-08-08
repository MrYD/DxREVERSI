#include "Botan.h"


Botan::Botan(int x,int y,int x2,int y2,TCHAR* GraphName)
{
	this->x1 = x;
	this->y1 = y;
	this->x2 = x + x2;
	this->y2 = y + y2;
	this->GraphName = GraphName;
	this->touchedNumber = 0;
}

Botan::Botan()
{}

Botan::~Botan()
{
}
void Botan::print()
{
	LoadGraphScreen(x1, y1, GraphName, TRUE);
}
bool Botan::isTouched(int x,int y)
{
		if  (x >= x1 && x <= x2 && y >= y1 && y <= y2)
		{
			touchedNumber++;
			return true;	
		}
	return false;
}