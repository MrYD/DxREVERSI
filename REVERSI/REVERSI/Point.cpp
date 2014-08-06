#pragma once
#include"Point.h"
#include<iostream>
Point::Point()
{}
Point::Point(int num, int space[8][8],int z)
{
	this->z = z;
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
	{
		if (num == space[i][j])
		{
			this->x = i;
			this->y = j;
			return;
		}
	}
	this->x = 0;
	this->y = 0;
	std::cout << "no such point!";
}
Point::Point(int num, int space[8][8])
{
	this->z = 0;
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
	{
		if (num == space[i][j])
		{
			this->x = i;
			this->y = j;
			return;
		}
	}
	this->x = 0;
	this->y = 0;
	std::cout << "no such point!";
}
Point::Point(int x, int y,int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Point::~Point()
{}
int Point::get_num(int space[8][8])
{
	return space[this->x][this->y];
}
void Point::set_z(int space[8][8])
{
	this->z= space[this->x][this->y];
}
void Point::set_z(int z)
{
	this->z = z;
}
void Point::set_x(int z)
{
	this->x = z;
}
void Point::set_y(int z)
{
	this->y = z;
}
int Point::get_z()
{
	return this->z;
}
int Point::get_x()
{
	return this->x;
}
int Point::get_y()
{
	return this->y;
}
