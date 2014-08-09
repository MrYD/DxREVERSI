#pragma once
#include "DxLib.h"
#include "Botan.h"
#include "DXBoard.h"
class Screen
{
public:
	Screen();
	~Screen();
	void init();
	void face();
protected:
	void print();
    void input();
};

