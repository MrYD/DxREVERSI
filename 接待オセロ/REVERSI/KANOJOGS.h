#pragma once
#include "GameScreen.h"
class KANOJOGS :
	public GameScreen
{
public:
	KANOJOGS(int* screenMod,Board *board);
	~KANOJOGS();
	void face();
	void print();
	int answer();
private:
	Botan* exBotan[2];
};

