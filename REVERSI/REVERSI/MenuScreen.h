#pragma once
#include "screen.h"

class MenuScreen :
	public Screen
{
public:
	MenuScreen();
	MenuScreen(int mode);
	~MenuScreen();
	void init(int mode);
	void face();
	void print();
	void input();
private:
	Botan menu_botan[4];
	int mode;
};

