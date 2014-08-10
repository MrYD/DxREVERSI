#pragma once
#include "DxLib.h"
#include "Botan.h"
#include "DXBoard.h"
class Screen
{
public:
	Screen();
	~Screen();
	virtual void init();
	virtual void face();
protected:
	virtual void print();
    virtual void input();
};

