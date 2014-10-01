#pragma once
#include "BasicRead.h"
class KANOJORead :
	public BasicRead
{
public:
	KANOJORead(Board board);
	~KANOJORead();
private:
    int judge();
	int judgeEnd();
	static int judgeQ(int fu[8][8]);
};

