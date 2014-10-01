#include "PointSheet.h"
#include"math.h"
#include<iostream>

PointSheet::~PointSheet()
{
	for (int j = 0; j < pointsNumber; j++)
	{
		delete points[j];
	}
}
PointSheet::PointSheet(int space[8][8])
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (space[i][j] != 0)
			{
				this->points[count] = new Point(i, j, 0);
				count++;
			}
		}
	}
	this->pointsNumber = count;
}
PointSheet::PointSheet(int space[8][8],int turnPlayer)
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (space[i][j] != 0)
			{
				this->points[count] = new Point(i, j, 0);
				count++;
			}
		}
	}
	this->pointsNumber = count;
	this->turnPlayer = turnPlayer;
}

void PointSheet::writeScore(Point point, int score)
{
	for (int i = 0; i < pointsNumber; i++)
	{
		if (points[i]->get_x() == point.get_x() && points[i]->get_y() == point.get_y())
		{
			points[i]->set_z(score);
			return;
		}
	}
	std::cout << "no such point!";
}
void PointSheet::writeScore(int number, int score)
{
	points[number - 1]->set_z(score);
}
//void PointSheet::addScore(Point point, int score)
//{
//	writeScore(point, point.get_z() + score);
//}
//void PointSheet::addScore(int number, int score)
//{
//	addScore(getPoint(number), score);
//}
int PointSheet::readScore(Point point)
{
	for (int i = 0; i < pointsNumber; i++)
	{
		if (points[i]->get_x() == point.get_x() && points[i]->get_y() == point.get_y())
		{
			return points[i]->get_z();
		}
	}
	std::cout << "no such point!";
	return 999999;
}
int PointSheet::readScore(int number)
{
	return  points[number-1]->get_z();
}
Point PointSheet::getMaxPoint()
{
	double max=-10000;
	for (int i = 0; i < pointsNumber;i++)
	{
		max = fmax(max, points[i]->get_z());
	}
	for (int i = 0; i < pointsNumber; i++)
	{
		if (max == points[i]->get_z())
			return *points[i];
	}
}
Point PointSheet::getMinPoint()
{
	double min = 10000;
	for (int i = 0; i < pointsNumber; i++)
	{
		min = fmin(min, points[i]->get_z());
	}
	for (int i = 0; i < pointsNumber; i++)
	{
		if (min == points[i]->get_z())
			return *points[i];
	}
}
Point PointSheet::choosePoint()
{
	if (turnPlayer == 1) return getMaxPoint();
	else return getMinPoint();
}
Point PointSheet::getPoint(int number)
{
	return *points[number-1];
}
int PointSheet::getMaxScore()
{
	double max = -10000;
	for (int i = 0; i < pointsNumber; i++)
	{
		max = fmax(max, points[i]->get_z());
	}
	return (int)max;
}
int PointSheet::getMinScore()
{
	double min = 10000;
	for (int i = 0; i < pointsNumber; i++)
	{
		min = fmin(min, points[i]->get_z());
	}
	return (int)min;
}
int PointSheet::chooseScore()
{
	if (turnPlayer == 1) return getMaxScore();
	else return getMinScore();
}

int PointSheet::getpointsNumber()
{
	return pointsNumber;
}
void PointSheet::print()
{
	std::cout << std::endl;
	for (int i = 0; i < pointsNumber; i++)
	{
		std::cout << i + 1 << " : " << points[i]->get_z()<<std::endl;
	}
}

int PointSheet::canCut(int i,int alfa,int beta)
{
	if (turnPlayer == 1 && points[i - 1]->get_z() >= alfa)  return 1; //player1の選んだalfa以上の値が選ばれるため、次手でこのシートは選ばれません.
	if (turnPlayer == 2 && points[i - 1]->get_z() <= beta)  return 2; //player2の選んだbeta以下の値が選ばれるため、次手でこのシートは選ばれません.
    return 0;
}