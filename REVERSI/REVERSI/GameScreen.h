#pragma once
#include "screen.h"
#include "AI.h"
#include "Botan.h"
#define BOARD  GetColor(0, 225, 50)
#define BLACK  GetColor(0, 0, 0)
#define RED GetColor(225,0,0)
#define LIGHT_BLACK GetColor(0,180,0)
#define WHITE  GetColor(225,225,225)
#define LIGHT_WHITE  GetColor(100,250,100)

class GameScreen :public Screen
{
public:
	GameScreen();
	GameScreen(int* mode,Board* board);
	~GameScreen();
	void init(int* mode,Board* board);
	void face();
	void print();
	void input();
	int getMode();
private:
	Botan botan[2];
	Board* board;
	void playerTurn();
	void cpuTurn();
	void result_MessageBox();
	void pass_MessageBox();
	void menu_MessageBox();
	bool isEnd;
	int* mode;
	int todo;
	int i;
	int j;
};

