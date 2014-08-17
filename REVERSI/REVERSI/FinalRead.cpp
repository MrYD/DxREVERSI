#include "FinalRead.h"
#include"Math.h"
#include"iostream"

FinalRead::FinalRead()
{
}

FinalRead::FinalRead(Board board) :ReadI(board)
{
	int num = board.getAbleNumber(1) * board.getAbleNumber(2);
	startFinalRead = 45;
	if (num <= 25)
	{
		startFinalRead = 44;
	}
	if (num >= 100)
	{
		startFinalRead = 43;
	}
}

FinalRead::~FinalRead()
{
}

void FinalRead::read()
{
	pointSheet = new PointSheet(board.ableSpace, board.getTurnPlayer());//評価用のシートを生成します.
	for (int i = 1; i <= board.getAbleNumber(); i++)
	{
		board.put(i);
		switch (board.getSCondition())
		{
		case 0:
			pointSheet->writeScore(i, alfaBeta(-10000, 10000));
			break;
		case 4:
			board.pass();
			pointSheet->writeScore(i, alfaBeta(-10000, 10000));
			board.undo();
			break;
		default:
			pointSheet->writeScore(i, board.getNumber(1) - board.getNumber(2));
			count++;
			break;
		}
		board.undo();
		if (pointSheet->readScore(i)>0 && board.getTurnPlayer() == 1 || pointSheet->readScore(i)<0 && board.getTurnPlayer() == 2)
		{
			return;
		}
	}
}

int FinalRead::answer()
{
	this->read();
	return ReadI::answer();
}

int FinalRead::alfaBeta(int alfa, int beta)
{
	if (board.getTurnPlayer() == 1)
	{
		for (int i = 1; i <= board.getAbleNumber(); i++)
		{

			board.put(i);
			switch (board.getSCondition())
			{
			case 0:
				alfa = fmax(alfa, alfaBeta(alfa, beta));
				break;
			case 4:
				board.pass();
				alfa = fmax(alfa, alfaBeta(alfa, beta));
				board.undo();
				break;
			default:
				alfa = board.getNumber(1) - board.getNumber(2);
				count++;
				break;
			}
			board.undo();
			if (alfa >= beta)
			{
				return beta;
			}
			if (alfa > 0)
			{
				return alfa;
			}
		}
		return alfa;
	}
	if (board.getTurnPlayer() == 2)
	{
		for (int i = 1; i <= board.getAbleNumber(); i++)
		{
			board.put(i);
			switch (board.getSCondition())
			{
			case 0:
				beta = fmin(beta, alfaBeta(alfa, beta));
				break;
			case 4:
				board.pass();
				beta = fmin(beta, alfaBeta(alfa, beta));
				board.undo();
				break;
			default:
				beta = board.getNumber(1) - board.getNumber(2);
				count++;
				break;
			}
			board.undo();
			if (alfa >= beta)
			{
				return alfa;
			}
			if (beta < 0)
			{
				return beta;
			}
		}
		return beta;
	}
}