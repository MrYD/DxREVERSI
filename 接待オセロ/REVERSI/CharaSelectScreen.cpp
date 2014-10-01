#include "CharaSelectScreen.h"


CharaSelectScreen::CharaSelectScreen(int* screenMode, int* chara)
{
	this->screenMode = screenMode;
	init(chara);
}


CharaSelectScreen::~CharaSelectScreen()
{
	for (int i=0; i < 3; i++)
	{
		delete botan[i];
	}
	for (int i=0; i < 4; i++)
	{
		delete Chara[i];
		delete CharaText[i];
	}


}

void CharaSelectScreen::init(int* chara)
{	
	this->chara = chara;
	this->num = 4;
	thisChara = num;
	botan[0] =new Botan(0, 0, 0, 0, "..\\REVERSI\\‰æ‘œ\\”wŒi1.png");
	botan[1] = new Botan(0, 0, 0, 0, "..\\REVERSI\\‰æ‘œ\\ƒXƒ^[ƒg.png");
	Chara[0] =new Botan(130, 20, 400, 450, "..\\REVERSI\\‰æ‘œ\\KANOJO.png");
	Chara[1] =new Botan(650, 50, 400, 450, "..\\REVERSI\\‰æ‘œ\\SENPAI.png");
	Chara[2] =new Botan(0, 50, 400, 450, "..\\REVERSI\\‰æ‘œ\\KANOJO_g.png");
	Chara[3] =new Botan(-250, 50, 450, 464, "..\\REVERSI\\‰æ‘œ\\KANOJO_g.png");
	CharaText[0] =new Botan(470, 40, 170, 459, "..\\REVERSI\\‰æ‘œ\\KANOJO_t.png");
	CharaText[1] = new Botan(470, 40, 170, 459, "..\\REVERSI\\‰æ‘œ\\SENPAI_t.png");
	CharaText[2] =new Botan(200, 0, 0, 0, "..\\REVERSI\\‰æ‘œ\\NO_t.png");
	CharaText[3] =new Botan(200, 0, 0, 0, "..\\REVERSI\\‰æ‘œ\\NO_t.png");
}

void CharaSelectScreen::face()
{
	print();
	input();
}

void CharaSelectScreen::input()
{
	int ClickX, ClickY, Button;
	if (GetMouseInputLog(&Button, &ClickX, &ClickY, TRUE) == 0)
	{
		if ((Button & MOUSE_INPUT_LEFT) != 0)
		{
			if (CharaText[thisChara % num]->isTouched(ClickX, ClickY))
			{
				*screenMode = 2;
				*chara = thisChara % num;
			}
			if (Chara[(thisChara - 1) % num]->isTouched(ClickX, ClickY))
			{
				Chara[(thisChara - 2) % num]->setPos(-400, 0);
				thisChara = (thisChara - 1) % num +num;
			}
			if (Chara[(thisChara + 1) % num]->isTouched(ClickX, ClickY))
			{
				Chara[(thisChara + 2) % num]->setPos(800, 0);
				thisChara = (thisChara + 1) % num +num;
			}
		}
		
	}
}
void CharaSelectScreen::print()
{
	int MouseX, MouseY;
	GetMousePoint(&MouseX, &MouseY);
	botan[0]->print();
	Chara[thisChara % num]->moveTo(0.5,130, 20);
	Chara[thisChara % num]->print();
	CharaText[thisChara % num]->print(MouseX,MouseY);
	Chara[(thisChara - 1) % num]->moveTo(0.5,-250, 50);
	Chara[(thisChara - 1) % num]->print(MouseX, MouseY);
	Chara[(thisChara + 1) % num]->moveTo(0.5,650, 50);
	Chara[(thisChara + 1) % num]->print(MouseX, MouseY);
}