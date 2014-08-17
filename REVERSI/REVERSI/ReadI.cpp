#include "ReadI.h"

ReadI::ReadI()
{
}
ReadI::ReadI(Board board)
{
	this->board = board;
}

ReadI::~ReadI()
{
	delete pointSheet;
}
void ReadI::read()
{}
int ReadI::answer()
{
	if (board.getTurnPlayer() == 1)
	{
		return pointSheet->getMaxPoint().get_num(board.ableSpace);
	}
	if (board.getTurnPlayer() == 2)
	{
		return pointSheet->getMinPoint().get_num(board.ableSpace);
	}
}