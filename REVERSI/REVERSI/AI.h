#pragma once
#include"Board.h"
#include"PointSheet.h"

class AI
{
public:
	AI(Board board);
	~AI();
	int readNumber;
	int startFinalRead;
	static int answer(Board *board);
	static int plmi(int player);
	void finalRead();
	void read(int num);
	int alfaBeta(int alfa, int beta);
	int alfaBeta_2(int num, int alfa, int beta);
	int judge();
	int judgeQ(int fu[8][8]);
	static int sign(int num);
	static bool isStop(int fu[8][8], int player);
private:
	PointSheet *pointSheet;
	Board board;
	int myPlayer;
	int firstTurn;
	int count;
};

