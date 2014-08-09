#pragma once
#include "Board.h"
#include "GameScreen.h"
#include "MenuScreen.h"
#define BOARD  GetColor(0, 225, 50)
#define BLACK  GetColor(0, 0, 0)
#define RED GetColor(225,0,0)
#define LIGHT_BLACK GetColor(0,180,0)
#define WHITE  GetColor(225,225,225)
#define LIGHT_WHITE  GetColor(100,250,100)
#define MENU 4
#define GAME 2
class DXBoard : public Board
{
public:
	DXBoard();
	~DXBoard();
	void init();
	void face();
private:
	int mode;
	GameScreen* gameScreen;
	MenuScreen* menuScreen;
	
};

