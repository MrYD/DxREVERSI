#pragma once
#include "IScreen.h"
#include "AI.h"
#include "Botan.h"
#define BOARD  GetColor(0, 225, 50)
#define BLACK  GetColor(0, 0, 0)
#define RED GetColor(225,0,0)
#define LIGHT_BLACK GetColor(50,50,50)
#define WHITE  GetColor(225,225,225)
#define LIGHT_WHITE  GetColor(150,150,150)
#define NON 0
#define PLAYER 1
#define CPU 2
#define PASS 5
#define CPUA 3
#define CPUB 4
#define END 6
#define BEGIN 7
#define TWOPLAYER 1
#define STBLACK 2
#define STWHITE 3

class GameScreen :public IScreen
{
public:
	GameScreen();
	GameScreen(int* screenMode, int mode,Board* board);
	~GameScreen();
	void init(int mode,Board* board);
	virtual void face();
	void print();
	void input();
	int getMode();
protected:
	Botan* botan[9];
	Board* board;
	Point ans;
	void printGame();
	void printPre();
	void result_MessageBox();
	void pass_MessageBox();
	void menu_MessageBox();
	bool isStart;
	bool isEnd;
	int mode;
	int* screenMode;
	int message;
	int todo;
	int i;
	int j;
};

