#include "AI.h"
AI::AI(Board board)
{
	basicRead = new BasicRead(board);
	finalRead = new FinalRead(board);
}
AI::~AI()
{
	delete basicRead;
	delete finalRead;
}
void AI::ininA(Board board)
{
	int num = board.getAbleNumber(1) * board.getAbleNumber(2);
	readNumber = 5;
	startFinalRead = 44;
	if (num <= 25)
	{
		readNumber = 5;
		startFinalRead = 43;
	}
	if (num >= 100)
	{
		readNumber = 5;
		startFinalRead = 45;
	}
}
void AI::ininB(Board board)
{
	int num = board.getAbleNumber(1) * board.getAbleNumber(2);
	readNumber = 5;
	startFinalRead = 44;
	if (num <= 25)
	{
		readNumber = 5;
		startFinalRead = 44;
	}
	if (num >= 100)
	{
		readNumber = 5;
		startFinalRead = 44;
	}
}
int AI::answer(Board board)
{
	AI* ai = new AI(board);
	ai->ininA(board);
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
int AI::answerA(Board board)
{
	AI* ai = new AI(board);
	ai->ininA(board);
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
int AI::answerB(Board board)
{
	AI* ai = new AI(board);
	ai->ininB(board);
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

int AI::answerKANOJO(Board board)
{
	int startFinalRead = 45;
	int readNumber = 4;
	int answer;
	KANOJORead *basicRead = new KANOJORead(board);
	FinalRead *finalRead = new FinalRead(board);
	
	if (board.getThisTurn() < startFinalRead)
	{
		answer= basicRead->KANOJORead::answer(readNumber);
	}
	else
	{
		answer= finalRead->answerRev();
	}
	delete basicRead;
	delete finalRead;
	return answer;
}
int AI::answerSENPAI(Board board)
{
	int startFinalRead;
	int readNumber;
	int answer;
	int num = board.getAbleNumber(1) * board.getAbleNumber(2);
	readNumber = 5;
	startFinalRead = 44;
	if (num <= 25)
	{
		readNumber = 5;
		startFinalRead = 43;
	}
	if (num >= 100)
	{
		readNumber = 5;
		startFinalRead = 45;
	}
	KANOJORead *basicRead = new KANOJORead(board);
	FinalRead *finalRead = new FinalRead(board);

	if (board.getThisTurn() < startFinalRead)
	{
		answer = basicRead->KANOJORead::answer(readNumber);
	}
	else
	{
		answer = finalRead->answerRev();
	}
	delete basicRead;
	delete finalRead;
	return answer;
}
