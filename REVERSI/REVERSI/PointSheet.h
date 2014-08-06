#pragma once
#include"Point.h"

class PointSheet
{
public:
	PointSheet(int space[8][8]);
	PointSheet(int space[8][8],int turnPlayer);
	~PointSheet();
	void writeScore(Point point, int score);
	void writeScore(int number, int score);
	void addScore(Point point, int score);
	void addScore(int number, int score);
	int  readScore(Point point);
	int  readScore(int number);
	Point getMaxPoint();
	Point getMinPoint();
	Point choosePoint();
	Point getPoint(int number);
	int getMaxScore();
	int getMinScore();
	int chooseScore();
	int getpointsNumber();
	void print();
	int canCut(int i,int alfa,int beta);
private:
	int turnPlayer;
	int pointsNumber;
	Point *points[64];
};

