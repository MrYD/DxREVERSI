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
protected:
	void read(int num);
	int alfaBeta(int num, int alfa, int beta);
    virtual int judge();
	virtual int judgeEnd();
	static int judgeQ(int fu[8][8]);
	static bool isStop(int fu[8][8],int player);
	static int sign(int num);
};

