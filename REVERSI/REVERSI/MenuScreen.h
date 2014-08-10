#pragma once
#include "screen.h"
#include "Botan.h"

class MenuScreen :
	public Screen
{
public:
	MenuScreen();
	MenuScreen(int* mode);
	~MenuScreen();
	void init(int* mode);
	void face();
	void print();
	void input();
	int getMode();
private:
	Botan menu_botan[4];
	int* mode;
};

