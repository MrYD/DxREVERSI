#include "BasicRead.h"
#include "math.h"
#include"iostream"

BasicRead::BasicRead()
{
}

BasicRead::BasicRead(Board board) :ReadI(board)
{
}

BasicRead::~BasicRead()
{
}
int BasicRead::answer(int num)
{
	this->read(num);
	return ReadI::answer();
}


void BasicRead::read(int num)
{
	pointSheet = new PointSheet(board.ableSpace, board.getTurnPlayer());//評価用のシートを生成します.
	for (int i = 1; i <= board.getAbleNumber(); i++)
	{
		board.put(i);
		switch (board.getSCondition())
		{
		case 0:
			pointSheet->writeScore(i, alfaBeta(num - 1, -10000, 10000));
			break;
		case 4:
			board.pass();
			pointSheet->writeScore(i, alfaBeta(num - 1, -10000, 10000));
			board.undo();
			break;
		default:
			pointSheet->writeScore(i, (board.getNumber(1) - board.getNumber(2)) * 100);
			count++;
			break;
		}
		board.undo();
	}
}

int BasicRead::alfaBeta(int num, int alfa, int beta)
{

	if (board.getTurnPlayer() == 1)
	{
		for (int i = 1; i <= board.getAbleNumber(); i++)
		{
			board.put(i);
			switch (board.getSCondition())
			{
			case 0:
				if (num > 0)
				{
					alfa = fmax(alfa, alfaBeta(num - 1, alfa, beta));
				}
				else
				{
					alfa = judge();
					count++;
				}
				break;
			case 4:
				board.pass();
				alfa = fmax(alfa, alfaBeta(num - 1, alfa, beta));
				board.undo();
				break;
			default:
				alfa = judgeEnd();
				count++;
				break;
			}
			board.undo();
			if (alfa >= beta)
			{
				return beta;
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
				if (num > 0)
				{
					beta = fmin(beta, alfaBeta(num - 1, alfa, beta));
				}
				else
				{
					beta = judge();
					count++;
				}
				break;
			case 4:
				board.pass();
				beta = fmin(beta, alfaBeta(num - 1, alfa, beta));
				board.undo();
				break;
			default:
				beta = judgeEnd();
				count++;
				break;
			}
			board.undo();
			if (alfa >= beta)
			{
				return alfa;
			}
		}
		return beta;
	}
}
int BasicRead::judgeEnd()
{
	return (board.getNumber(1) - board.getNumber(2)) * 100;
}

int BasicRead::judge()
{
	int score;
	int fu[8][8];
	score = judgeQ(board.log[board.getThisTurn()]);
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
	{
		fu[i][7 - j] = board.log[board.getThisTurn()][i][j];
	}
	score += judgeQ(fu);
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
	{
		fu[7 - i][j] = board.log[board.getThisTurn()][i][j];
	}
	score += judgeQ(fu);
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
	{
		fu[7 - i][7 - j] = board.log[board.getThisTurn()][i][j];
	}
	score += judgeQ(fu);
	
	score += board.getAbleNumber(1);
	score -= board.getAbleNumber(2);
	score -= board.getNumber(1) / 2;
	score += board.getNumber(2) / 2;
	return score;
}


int BasicRead::judgeQ(int fu[8][8])
{
	int score = 0;
	if (fu[0][0] == 1)
	{
		score += 100;
		if (!isStop(fu, 1))
		{
			score -= 50;
		}
	}
	else if (fu[0][0] == 2)
	{
		score -= 100;
		if (!isStop(fu, 2))
		{
			score += 50;
		}
	}
	else
	{
		score -= sign(fu[1][1]) * 100;
		if (Board::isAble(fu, Point(0, 0, 0), 1))
		{
			score += 100;
		}
		if (Board::isAble(fu, Point(0, 0, 0), 2))
		{
			score -= 100;
		}
	}
	return score;
}


bool BasicRead::isStop(int fu[8][8], int player)
{
	int oponent = Board::oponent(player);
	int count = 1;
	int check = player;
	while (check == player && count < 8)
	{
		check = fu[0][count];
		count++;
	}
	if (check == oponent)
	{
		while (check == oponent && count < 8)
		{
			check = fu[0][count];
			count++;
		}
		if (check == player && count != 7)
		{
			count = 1;
			check = player;
			while (check == player && count < 8)
			{
				check = fu[count][0];
				count++;
			}
			if (check == oponent)
			{
				while (check == oponent && count < 8)
				{
					check = fu[count][0];
					count++;
				}
				if (check == player && count != 7)
				{
					return true;
				}
			}
		}
	}
	return false;
}

int BasicRead::sign(int num)
{
	if (num == 2) num = -1;
	return num;
}