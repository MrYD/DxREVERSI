#pragma once
#include "tchar.h"
#include "DxLib.h"
class Botan
{
public:
	Botan(int x, int y, int graph_x, int graph_y, TCHAR* GraphName);
	Botan(float x, float y, int graph_x, int graph_y, TCHAR* GraphName);
	Botan(int x, int y, int graph_x, int graph_y, TCHAR* GraphName, TCHAR* TouchedName);
	Botan();
	~Botan();
	void setPos(int x, int y);
	void print();
	void printAt(int x,int y);
	void printAt(int x, int y,int MouseX,int MouseY);
	void printAt(int x, int y, int MouseX, int MouseY,int light);
	void printWhite();
	void printWhite(bool isBox);
	void print(bool isBox);
	void print(int x,int y);
	void print(int x, int y,bool isBox);
	void touched();
	bool isTouched(int x,int y);
	void moveTo(float speed, int x, int y);
	int getX();
	int getY();
	TCHAR getName();
private:
	int touchedNumber;
	int x1;
	int y1;
	int x2;
	int y2;
	TCHAR* GraphName;
	TCHAR* TouchedName;
};

