#pragma once
#include"Point.h"
class Board
{
public:
	Board();
	Board(int firstPlayer);
	~Board();
    static void clear(int arr[8][8]);
	static int oponent(int player);
	static bool isAble(int fu[8][8], Point point,int player);
	void init(int firstPlayer);
	int put(Point point);
	int put(int num);
	void undo();
	void pass();
	void nextTurn();
	int getNumber(int player);
	int getAbleNumber(int player);
	int getAbleNumber();
	int getThisTurn();
	int getTurnPlayer();
	int getCondition();
	int getCondition(int player);
	int getSCondition();
	int ableSpace[8][8];
	int log[100][8][8];
	Point point[100];
protected:
	void setAbleSpace();
	int thisTurn;
	int turnPlayer;
	int ableNumber;
};

class GameBoard : public Board
{
public:
	GameBoard();
	~GameBoard();
	bool doTurn();
	void print();
	void printResult();
	char* ston(int player);
private:
	int mode;
};

