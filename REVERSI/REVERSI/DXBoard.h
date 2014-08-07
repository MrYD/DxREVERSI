#pragma once
#include "Board.h"
#include "DxLib.h"
#include "Botan.h"
#define BOARD  GetColor(0, 225, 50)
#define BLACK  GetColor(0, 0, 0)
#define RED GetColor(225,0,0)
#define LIGHT_BLACK GetColor(0,180,0)
#define WHITE  GetColor(225,225,225)
#define LIGHT_WHITE  GetColor(100,250,100)
class DXBoard : public Board
{
public:
	DXBoard();
	~DXBoard();
	void init();
	void getBoard();
	void menu();
	void print();
private:
	int mode;
	bool isEnd;
	void input(int* num,int* i,int* j);
	void printBoard();
	void result_MessageBox();
	void printBotans();
	void pass_MessageBox();
	void menu_MessageBox();
//	Botan botan[5];
	
};

