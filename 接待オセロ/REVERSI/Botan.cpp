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
Botan::Botan(float x,float  y, int x2, int y2, TCHAR* GraphName)
{
	this->x1 = (int)(x*640);
	this->y1 = (int)(y*480);
	this->x2 = x + x2;
	this->y2 = y + y2;
	this->GraphName = GraphName;
	this->touchedNumber = 0;
}
Botan::Botan(int x, int  y, int x2, int y2, TCHAR* GraphName, TCHAR* TouchedName)
{
	this->x1 = x;
	this->y1 = y;
	this->x2 = x + x2;
	this->y2 = y + y2;
	this->GraphName = GraphName;
	this->TouchedName = TouchedName;
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

void Botan::printWhite()
{
	int Handle = LoadGraph(GraphName);
	GraphFilter(Handle, DX_GRAPH_FILTER_HSB, 0, 0, 0, 50);
	DrawGraph(x1, y1, Handle, TRUE);
}
void Botan::printWhite(bool isBox)
{
	if (isBox)
	{
		printWhite();
		DrawBox(x1, y1, x2, y2, GetColor(0, 0, 0), FALSE);
	}
	else
	{
		printWhite();
	}
}
void Botan::print(int x, int y)
{
	if (isTouched(x, y))
	{
		printWhite();
	}
	else
	{
		print();
	}
}
void Botan::print(int x, int y,bool isBox)
{
	if (isBox)
	{
		print(x, y);
		DrawBox(x1, y1, x2, y2, GetColor(0, 0, 0), FALSE);
	}
	else
	{
		print(x, y);
	}
}
void Botan::print(bool isBox)
{
	if (isBox)
	{
		print();
		DrawBox(x1, y1, x2, y2, GetColor(0, 0, 0), FALSE);
	}
	else
	{
		print();
	}
}
void Botan::printAt(int x, int y)
{
	LoadGraphScreen(x, y, GraphName, TRUE);
}
void Botan::printAt(int x, int y,int MouseX,int MouseY)
{
	if (MouseX >= x && MouseX <= x + x2 - x1 && MouseY >= y && MouseY <= y + y2 - y1)
	{
		int Handle = LoadGraph(GraphName);
		GraphFilter(Handle, DX_GRAPH_FILTER_HSB, 0, 0, 0, 50);
		DrawGraph(x, y, Handle, TRUE);
	}
	else
	{
		LoadGraphScreen(x, y, GraphName, TRUE);
	}
}
void Botan::printAt(int x, int y, int MouseX, int MouseY,int light)
{
	if (MouseX >= x && MouseX <= x + x2 - x1 && MouseY >= y && MouseY <= y + y2 - y1)
	{
		int Handle = LoadGraph(GraphName);
		GraphFilter(Handle, DX_GRAPH_FILTER_HSB, 0, 0, 0, light);
		DrawGraph(x, y, Handle, TRUE);
	}
	else
	{
		LoadGraphScreen(x, y, GraphName, TRUE);
	}
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
void Botan::touched()
{
	LoadGraphScreen(x1, y1, TouchedName, TRUE);
}

TCHAR Botan::getName()
{
	return *GraphName;
}

void Botan::setPos(int x, int y)
{
	this->x2 -= this->x1;
	this->y2 -= this->y1;
	this->x1 = x;
	this->y1 = y;
	this->x2 += x;
	this->y2 += y;
}

void Botan::moveTo(float speed, int x, int y)
{
	setPos(x1 + (x - x1)*speed, y1+(y - y1)*speed);
}

int Botan::getX()
{
	return x1;
}
int Botan::getY()
{
	return y1;
}