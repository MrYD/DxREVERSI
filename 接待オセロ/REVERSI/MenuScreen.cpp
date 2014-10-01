#include "MenuScreen.h"

MenuScreen::MenuScreen()
{
}
MenuScreen::MenuScreen(int* screenMode,int* mode)
{
	this->screenMode = screenMode;
	init(mode);
}

MenuScreen::~MenuScreen()
{
	for (int i = 0; i < 7; i++)
	{
		delete botan[i];
	}
}
int MenuScreen::getMode()
{
	return *mode;
}

void MenuScreen::init(int* mode)
{
	this->mode = mode;
	botan[0] =new Botan(220, 30, 0, 0, "..\\REVERSI\\画像\\title.png");
	botan[1] = new Botan(600, 200, 400, 450, "..\\REVERSI\\画像\\KANOJO.png", "..\\REVERSI\\画像\\KANOJO_p.png");
	botan[5] = new Botan(600, 200, 0, 0, "..\\REVERSI\\画像\\KANOJO_g.png");
	botan[2] =new Botan(220, 200, 300, 400, "..\\REVERSI\\画像\\tex(1).png");
	botan[3] =new Botan(180, 280, 100, 100, "..\\REVERSI\\画像\\スタート.png");
	botan[4] =new Botan(0, 0, 0, 0, "..\\REVERSI\\画像\\背景1.png");
	botan[6] = new Botan(280, 280, 0, 0, "..\\REVERSI\\画像\\吹き出し(1).png");
}
void MenuScreen::face()
{
	print();
	input();
}

void MenuScreen::input()
{
	int ClickX, ClickY, Button;
	if (GetMouseInputLog(&Button, &ClickX, &ClickY, TRUE) == 0)
	{
		if ((Button & MOUSE_INPUT_LEFT) != 0)
		{
			if (botan[2]->isTouched(ClickX, ClickY))
			{
				*screenMode = 1;
				*mode = 2;
			}
		}
	}
}

void MenuScreen::print()
{
	int MouseX, MouseY;
	GetMousePoint(&MouseX, &MouseY);
	botan[4]->print();
	botan[0]->print();
	botan[2]->moveTo(0.3,120, 200);
    botan[2]->print(MouseX,MouseY);
	botan[5]->moveTo(1, 400, 200);
	botan[5]->print();
	botan[1]->moveTo(1, 430, 200);
	botan[1]->print();
	
}