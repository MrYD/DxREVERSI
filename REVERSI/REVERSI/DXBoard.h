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
#define MENU 4
#define GAME 2
class DXBoard : public Board
{
public:
	DXBoard();
	~DXBoard();
	void init();
	void game();
	void menu();
private:
	int mode;
	bool isEnd;
	void print_game();
	void print_menue();
	void input_game(int* num,int* i,int* j);
	void input_menu(int* num);
	void result_MessageBox();
	void pass_MessageBox();
	void menu_MessageBox();
	Botan menu_botan[MENU];
	Botan game_botan[GAME];
	
};

