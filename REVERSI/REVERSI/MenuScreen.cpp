#include "MenuScreen.h"

MenuScreen::MenuScreen()
{
}
MenuScreen::MenuScreen(int* mode)
{
	init(mode);
}

MenuScreen::~MenuScreen()
{
}
int MenuScreen::getMode()
{
	return *mode;
}

void MenuScreen::init(int* mode)
{
	this->mode = mode;
	menu_botan[0] = Botan(150, 100, 341, 123, "..\\REVERSI\\‰æ‘œ\\REVERCI_title.png");
	menu_botan[1] = Botan(50, 350, 150, 50, "..\\REVERSI\\‰æ‘œ\\2PLAYER.png");
	menu_botan[2] = Botan(250, 350, 150, 50, "..\\REVERSI\\‰æ‘œ\\BLACK.png");
	menu_botan[3] = Botan(450, 350, 150, 50, "..\\REVERSI\\‰æ‘œ\\WHITE.png");
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
			if (menu_botan[0].isTouched(ClickX, ClickY))
			{
				*mode = 4;
			}
			if (menu_botan[1].isTouched(ClickX, ClickY))
			{
				*mode = 1;
			}
			if (menu_botan[2].isTouched(ClickX, ClickY))
			{
				*mode = 2;
			}
			if (menu_botan[3].isTouched(ClickX, ClickY))
			{
				*mode = 3;
			}
		}
	}
}

void MenuScreen::print()
{
	for (int i = 0; i < 4; i++)
	{
		menu_botan[i].print();
	}
}