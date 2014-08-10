#pragma once
#include "Board.h"
#include "GameScreen.h"
#include "MenuScreen.h"

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

