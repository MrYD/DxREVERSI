#include "DXBoard.h"
#include "AI.h"

DXBoard::DXBoard()
{
	this->init();
}
DXBoard::~DXBoard()
{
	delete menuScreen;
	delete charaScreen;
	delete gameScreen;
}
void DXBoard::init()
{
	mode = 0;
	screenMode = 0;
	Board::init(1);
	menuScreen = new MenuScreen(&screenMode,&mode);
	charaScreen = new CharaSelectScreen(&screenMode, &chara);
}



void DXBoard::face()
{
	switch (screenMode)
	{
	case 0:
		menuScreen->face();
		break;
	case 1:
		charaScreen->face();
		if (screenMode == 0) init();
		break;
	case 2:
		switch (chara)
		{
		default:
			screenMode = 1;
			break;
		case 0:
	        gameScreen = new KANOJOGS(&screenMode,this);
			screenMode = 3;
			break;
		case 1:
			gameScreen = new SENPAIGS(&screenMode, this);
			screenMode = 3;
			break;
		}
	case 3:
		gameScreen->face();
		if (screenMode == 0) init();
		break;
	}


}
