#pragma once
#include "GameScreen.h"
class SENPAIGS :
	public GameScreen
{
public:
	SENPAIGS(int* screenMod, Board *board);
	~SENPAIGS();
	void face();
	void print();
	int answer();
private:
	Botan* exBotan[2];
};

