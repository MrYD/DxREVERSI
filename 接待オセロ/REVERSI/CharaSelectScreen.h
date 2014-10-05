#pragma once
#include "IScreen.h"
#include "Botan.h"
#define NUMBER 3;
class CharaSelectScreen :
	public IScreen
{
public:
	CharaSelectScreen(int* screenmode,int* chara);
	~CharaSelectScreen();
	void init(int* chara);
	void face();
	void print();
	void input();
private:
	Botan* botan[3];
	Botan* Chara[4];
	Botan* CharaText[4];
	int num;
	int *chara;
	int *screenMode;
	int thisChara;
};

