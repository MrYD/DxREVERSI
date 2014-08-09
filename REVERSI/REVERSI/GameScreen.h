#pragma once
#include "screen.h"
#include "AI.h"
class GameScreen :public Screen
{
public:
	GameScreen();
	GameScreen(int mode,Board* board);
	~GameScreen();
	void init(int mode,Board* board);
	void face();
	void print();
	void input();
	int getMode();
private:
	Botan botan[2];
	Board* board;
	void result_MessageBox();
	void pass_MessageBox();
	void menu_MessageBox();
	bool isEnd;
	int mode;
	int num;
	int i;
	int j;
};

