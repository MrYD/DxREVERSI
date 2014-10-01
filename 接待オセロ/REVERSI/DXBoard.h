#pragma once
#include "Board.h"
#include "KANOJOGS.h"
#include "SENPAIGS.h"
#include "MenuScreen.h"
#include "CharaSelectScreen.h"

class DXBoard : public Board
{
public:
	DXBoard();
	~DXBoard();
	void init();
	void face();
private:
	int mode;
	int chara;
	int screenMode;
	MenuScreen* menuScreen;
	CharaSelectScreen* charaScreen;
	GameScreen* gameScreen;
};

