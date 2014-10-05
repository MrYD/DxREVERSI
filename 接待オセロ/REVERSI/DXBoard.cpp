#include "DXBoard.h"
#include "AI.h"

DXBoard::DXBoard()
{
	this->init();
}
DXBoard::~DXBoard()
{
	for (int i = 0; i < 3; i++)
	{
		delete screen[i];
	}
}
void DXBoard::init()
{
	mode = 0;
	screenMode = 0;
	Board::init(1);
	screen[0] = new MenuScreen(&screenMode,&mode);
	screen[1] = new CharaSelectScreen(&screenMode, &chara);
	screen[2] = new GameScreen();
}



void DXBoard::face()
{
	switch (screenMode)
	{
	case 0:
		screen[0]->face();
		break;
	case 1:
		screen[1]->face();
		if (screenMode == 0) init();
		break;
	case 2:
		switch (chara)
		{
		default:
			screenMode = 1;
			break;
		case 0:
	        screen[2] = new KANOJOGS(&screenMode,this);
			screenMode = 3;
			break;
		case 1:
			screen[2] = new SENPAIGS(&screenMode, this);
			screenMode = 3;
			break;
		}
	case 3:
		screen[2]->face();
		if (screenMode == 0) init();
		break;
	}


}
