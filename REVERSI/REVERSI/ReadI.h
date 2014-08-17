#pragma once
#include"Board.h"
#include"PointSheet.h"
class ReadI
{
public:
	ReadI();
	ReadI(Board board);
	~ReadI();
    int answer();
protected:
	Board board;
	PointSheet *pointSheet;
	void read();
	int count;
};

