#include "AI.h"
#include"Math.h"
#include"PointSheet.h"
#include"iostream"
#include<memory>
void test(int A[8][8])
{
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << A[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
AI::AI(Board board)
{
	this->board = board;
	this->myPlayer = board.getTurnPlayer();
	this->count = 0;
	this->firstTurn = board.getThisTurn();
	readNumber = 6;
	startFinalRead = 43;
	int num = board.getAbleNumber(1) * board.getAbleNumber(2);
	if (num <= 25)
	{
		readNumber = 8;
		startFinalRead = 42;
	}
	if (num >= 100)
	{
		readNumber = 5;
		startFinalRead = 44;
	}
}
AI::~AI()
{
	delete pointSheet;
}
int AI::answer(Board* board)
{
	AI *ai = new AI(*board);
	if (board->getThisTurn() + 1 < ai->startFinalRead) ai->read(ai->readNumber);
	else ai->finalRead();
	ai->pointSheet->print();
	int ans;
	if (board->getTurnPlayer() == 1)
		ans = ai->pointSheet->getMaxPoint().get_num(board->ableSpace);
	if (board->getTurnPlayer() == 2)
		ans = ai->pointSheet->getMinPoint().get_num(board->ableSpace);
	delete ai;
	return ans;
}
void AI::finalRead()
{
		PointSheet *PS = new PointSheet(board.ableSpace, board.getTurnPlayer());//評価用のシートを生成します.
		for (int i = 1; i <= board.getAbleNumber(); i++)
		{
			board.put(i);
			switch (board.getSCondition())
			{
			case 0:
				PS->writeScore(i, alfaBeta(-10000, 10000));
				break;
			case 4:
				board.pass();
				PS->writeScore(i, alfaBeta(-10000, 10000));
				board.undo();
				break;
			default:
				PS->writeScore(i, board.getNumber(1) - board.getNumber(2));
				count++;
				break;
			}
			board.undo();
			if (PS->readScore(i)>0 && board.getTurnPlayer()==1 || PS->readScore(i)<0 && board.getTurnPlayer()==2)
			{
				pointSheet = PS;
				return;
			}
		}
		pointSheet = PS;
}
int AI::alfaBeta(int alfa, int beta)
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
				beta = fmin(beta, alfaBeta( alfa, beta));
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
void AI::read(int num)
{
	PointSheet *PS = new PointSheet(board.ableSpace, board.getTurnPlayer());//評価用のシートを生成します.
	for (int i = 1; i <= board.getAbleNumber(); i++)
	{
		board.put(i);
		switch (board.getSCondition())
		{
		case 0:
			PS->writeScore(i, alfaBeta_2(num - 1,-10000, 10000));
			break;
		case 4:
			board.pass();
			PS->writeScore(i, alfaBeta_2(num - 1,-10000, 10000));
			board.undo();
			break;
		default:
			PS->writeScore(i, (board.getNumber(1) - board.getNumber(2))*100);
			count++;
			break;
		}
		board.undo();
	}
	pointSheet = PS;
}
int AI::alfaBeta_2(int num,int alfa, int beta)
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
					alfa = fmax(alfa, alfaBeta_2(num - 1, alfa, beta));
				}
				else
				{
					alfa = judge();
					count++;
				}
				break;
			case 4:
				board.pass();
				alfa = fmax(alfa, alfaBeta_2(num - 1,alfa, beta));
				board.undo();
				break;
			default:
				alfa = (board.getNumber(1) - board.getNumber(2))*100;
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
					beta = fmin(beta, alfaBeta_2(num - 1,alfa, beta));
				}
				else
				{
					beta = judge();
					count++;
				}
				break;
			case 4:
				board.pass();
				beta = fmin(beta, alfaBeta_2(num - 1,alfa, beta));
				board.undo();
				break;
			default:
				beta = (board.getNumber(1) - board.getNumber(2))*100;
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
int AI::plmi(int player)
{
	if (player = 1) return 1;
	else return -1;
}
int AI::sign(int num)
{
	if (num == 2) num = -1;
	return num;
}
int AI::judge()
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
	return score;
}

int AI::judgeQ(int fu[8][8])
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
		if (Board::isAble(fu, Point(0, 0,0), 1))
		{
			score += 100;
		}
		if (Board::isAble(fu, Point(0, 0,0), 2))
		{
			score -= 100;
		}
	}
	return score;
}

bool AI::isStop(int fu[8][8], int player)
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

