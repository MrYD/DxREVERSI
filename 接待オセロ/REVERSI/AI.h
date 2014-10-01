#pragma once
#include"Math.h"
#include"PointSheet.h"
#include"iostream"
#include<memory>
#include"Board.h"
#include"PointSheet.h"
#include"FinalRead.h"
#include "KANOJORead.h"
class AI
{
public:
	AI(Board board);
	~AI();
	static int answer(Board board);
	static int answerA(Board board);
	static int answerB(Board board);
	static int answerKANOJO(Board board);
	static int answerSENPAI(Board board);
private:
	BasicRead *basicRead;
	FinalRead *finalRead;
	void ininA(Board board);
	void ininB(Board board);
	int readNumber;
	int startFinalRead;
};

