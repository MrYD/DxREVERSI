#include "KANOJORead.h"


KANOJORead::KANOJORead(Board board) :BasicRead(board)
{
}


KANOJORead::~KANOJORead()
{
}
int KANOJORead::judgeEnd()
{
	return -BasicRead::judgeEnd();
}

int KANOJORead::judge()
{
	int score;
	int fu[8][8];
	score = this->judgeQ(board.log[board.getThisTurn()]);
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
	{
		fu[i][7 - j] = board.log[board.getThisTurn()][i][j];
	}
	score += this->judgeQ(fu);
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
	{
		fu[7 - i][j] = board.log[board.getThisTurn()][i][j];
	}
	score += this->judgeQ(fu);
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
	{
		fu[7 - i][7 - j] = board.log[board.getThisTurn()][i][j];
	}
	score += this->judgeQ(fu);
	score -= board.getNumber(1);
	score += board.getNumber(2);
	return score;
}
int KANOJORead::judgeQ(int fu[8][8])
{
	int score = 0;
	if (fu[0][0] == 1)
	{
		score -= 100;
	}
	else if (fu[0][0] == 2)
	{
		score += 100;
	}
	else
	{
		if (Board::isAble(fu, Point(0, 0, 0), 1))
		{
			score -= 50;
		}
		if (Board::isAble(fu, Point(0, 0, 0), 2))
		{
			score += 50;
		}
	}
	return score;
}