#pragma once
#include "ReadI.h"
class FinalRead :
	public ReadI
{
public:
	FinalRead();
	FinalRead(Board board);
	~FinalRead();
	int answer();
private:
	void read();
	int alfaBeta(int alfa, int beta);
	int startFinalRead;
};

