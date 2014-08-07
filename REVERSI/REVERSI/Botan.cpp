//#include "Botan.h"
//
//
//Botan::Botan(int x,int y,int x2,int y2,TCHAR* GraphName)
//{
//	this->x1 = x;
//	this->y1 = y;
//	this->x2 = x + x2;
//	this->y2 = y + y2;
//	this->GraphName = GraphName;
//	this->touchedNumber = 0;
//}
//
//
//Botan::~Botan()
//{
//}
//void Botan::print()
//{
//	LoadGraphScreen(x1, y1, GraphName, TRUE);
//}
//bool Botan::isTouched()
//{
//	int ClickX, ClickY, Button;
//	if (GetMouseInputLog(&Button, &ClickX, &ClickY, TRUE) == 0)
//	{
//		if ((Button & MOUSE_INPUT_LEFT) != 0 && (ClickX >= x1 && ClickX <= x2 && ClickY >= y1 && ClickY <= y2))
//		{
//			touchedNumber++;
//			return true;	
//		}
//	}
//	return false;
//}