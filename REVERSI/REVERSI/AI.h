#pragma once
#include"Board.h"
#include"PointSheet.h"
#include"BasicRead.h"
#include"FinalRead.h"
class AI
{
public:
	AI(Board board);
	~AI();
	static int answer(Board board);
private:
	BasicRead *basicRead;
	FinalRead *finalRead;
	int readNumber;
	int startFinalRead;
};

