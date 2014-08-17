#include "AI.h"
#include"Math.h"
#include"PointSheet.h"
#include"iostream"
#include<memory>

AI::AI(Board board)
{
	basicRead = new BasicRead(board);
	finalRead = new FinalRead(board);
	int num = board.getAbleNumber(1) * board.getAbleNumber(2);
	readNumber = 6;
	startFinalRead = 44;
	if (num <= 25)
	{
		readNumber = 8;
		startFinalRead = 43;
	}
	if (num >= 100)
	{
		readNumber = 5;
		startFinalRead = 45;
	}
}
AI::~AI()
{
	delete basicRead;
	delete finalRead;
}
int AI::answer(Board board)
{
	AI* ai = new AI(board);
	if (board.getThisTurn() < ai->startFinalRead)
	{
		return ai->basicRead->answer(ai->readNumber);
	}
	else
	{
		return ai->finalRead->answer();
	}
	delete ai;
}

