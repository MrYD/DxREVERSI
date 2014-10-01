#pragma once
#include "ReadI.h"
class BasicRead :
	public ReadI
{
public:
	BasicRead();
	BasicRead(Board board);
	~BasicRead();
	int answer(int num);
private:
	void read(int num);
	int alfaBeta(int num, int alfa, int beta);
    int judge();
//	int judgeReverse();
	static int judgeQ(int fu[8][8]);
//	static int judgeQR(int fu[8][8]);
	static bool isStop(int fu[8][8],int player);
	static int sign(int num);
};

