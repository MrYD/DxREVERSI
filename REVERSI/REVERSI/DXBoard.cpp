#include "DXBoard.h"
#include "AI.h"

DXBoard::DXBoard()
{
	this->init();
}
DXBoard::~DXBoard()
{
	delete gameScreen;
	delete menuScreen;
}
void DXBoard::init()
{
	mode = 0;
	Board::init(1);
	menuScreen =new MenuScreen(mode);
	gameScreen =new GameScreen(mode,this);
}

void DXBoard::face()
{
	if (mode == 0)
	{
		menuScreen->face();
	}
	else
	{
		gameScreen->face();
		this->mode = gameScreen->getMode();
	}
}
