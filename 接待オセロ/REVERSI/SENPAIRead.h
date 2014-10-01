#pragma once
#include "BasicRead.h"
class SENPAIRead :
	public BasicRead
{
public:
	SENPAIRead(Board);
	~SENPAIRead();
private:
	int judge();
	int judgeEnd();
	static int judgeQ(int fu[8][8]);
};

