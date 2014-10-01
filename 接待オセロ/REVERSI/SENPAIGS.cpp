#include "SENPAIGS.h"


SENPAIGS::SENPAIGS(int* screenMod, Board *board) :GameScreen(screenMod, 2, board)
{
	exBotan[0] = new Botan(580, 10, 200, 180, "..\\REVERSI\\�摜\\SENPAI_s.png");
	exBotan[1] = new Botan(0, 10, 200, 180, "..\\REVERSI\\�摜\\�����o��.png");
}


SENPAIGS::~SENPAIGS()
{
	for (int i = 0; i < 2; i++)
	{
		delete exBotan[i];
	}
}

void SENPAIGS::face()
{
	GameScreen::face();
	print();
	if (message == CPU)
	{
		ans = Point(answer(), board->ableSpace);
	}
	
}

void SENPAIGS::print()
{
	GameScreen::print();
	exBotan[0]->print();
	exBotan[1]->print();
	switch (message)
	{
	default:
		break;
	case BEGIN:
		DrawFormatString(100, 60, BLACK, "�l�ƃI�Z������낤�B");
		ScreenFlip();
		break;
	case CPU:
		DrawFormatString(100, 60, BLACK, "���̃^�[��...");
		ScreenFlip();
		break;
	case PLAYER:
		if (board->getThisTurn() == 0){
			DrawFormatString(100, 60, BLACK, "��s�͏��낤�B");
		}
		else{
			DrawFormatString(100, 60, BLACK, "����...�ł�...");
		}
		ScreenFlip();
		break;
	case PASS:
		DrawFormatString(100, 60, BLACK, "�p�X��...");
		ScreenFlip();
		break;
	case END:
		if (board->getCondition() == 2)
		{
			DrawFormatString(100, 60, BLACK, "�t�t�b �y����������...");
			ScreenFlip();
		}
		if (board->getCondition() == 1)
		{
			DrawFormatString(100, 60, BLACK, "... ...�B");
			ScreenFlip();
		}
		if (board->getCondition() == 3)
		{
			DrawFormatString(100, 60, BLACK, "�R�C�c... �o����I");
			ScreenFlip();
		}
		break;
	}
}
int SENPAIGS::answer()
{
	int startFinalRead;
	int readNumber;
	int answer;
	int num = board->getAbleNumber(1) * board->getAbleNumber(2);
	readNumber = 5;
	startFinalRead = 44;
	if (num <= 25)
	{
		readNumber = 5;
		startFinalRead = 43;
	}
	if (num >= 100)
	{
		readNumber = 5;
		startFinalRead = 45;
	}
	KANOJORead *basicRead = new KANOJORead(*board);
	FinalRead *finalRead = new FinalRead(*board);

	if (board->getThisTurn() < startFinalRead)
	{
		answer = basicRead->KANOJORead::answer(readNumber);
	}
	else
	{
		answer = finalRead->answerRev();
	}
	delete basicRead;
	delete finalRead;
	return answer;
}