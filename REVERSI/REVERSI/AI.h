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
	static int answer(Board* board);
	static int answerA(Board board);
	static int answerB(Board board);
private:
	BasicRead *basicRead;
	FinalRead *finalRead;
	void ininA(Board board);
	void ininB(Board board);
	int readNumber;
	int startFinalRead;
};

