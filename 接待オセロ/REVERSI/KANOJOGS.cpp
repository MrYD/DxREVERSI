#include "KANOJOGS.h"


KANOJOGS::KANOJOGS(int* screenMod, Board *board) :GameScreen(screenMod,3,board)
{
	exBotan[0] = new Botan(580, 10, 200, 180, "..\\REVERSI\\�摜\\KANOJO_s.png");
	exBotan[1] = new Botan(0, 10, 200, 180, "..\\REVERSI\\�摜\\�����o��.png");
}


KANOJOGS::~KANOJOGS()
{
	for (int i = 0; i < 2; i++)
	{
		delete exBotan[i];
	}
}

void KANOJOGS::face()
{
	GameScreen::face();
	print();
	if (message == CPU)
	{
		ans = Point(answer(), board->ableSpace);
	}
}

void KANOJOGS::print()
{
	GameScreen::print();
	exBotan[0]->print();
	exBotan[1]->print();
	switch (message)
	{
	default:
		break;
	case BEGIN:
		DrawFormatString(100, 60, BLACK, "�I�Z���͓��ӂȂ񂾂���I");
		ScreenFlip();
		break;
	case CPU:
		if (board->getThisTurn() == 0)
		{
			DrawFormatString(100, 60, BLACK, "������ˁI");
			ScreenFlip();
			WaitTimer(1000);
		}
		else
		{
			DrawFormatString(100, 60, BLACK, "���[��ƂˁB");
			ScreenFlip();
		}
		break;
	case PLAYER:
		DrawFormatString(100, 60, BLACK, "�͂����A���񂽂̔Ԃ�I");
		ScreenFlip();
		break;
	case PASS:
		DrawFormatString(100, 60, BLACK, "�p�X�ˁI");
		ScreenFlip();
		break;
	case END:
		if (board->getCondition() == 1)
		{
			DrawFormatString(100, 60, BLACK, "�˂��A�����ł���I");
			ScreenFlip();
		}
		if (board->getCondition() == 2)
		{
			DrawFormatString(100, 60, BLACK, "�Ђ��ǁ[���I���񂽂Ȃ񂩌����I�I");
			ScreenFlip();
		}
		if (board->getCondition() == 3)
		{
			DrawFormatString(100, 60, BLACK, "���񂽂���邶��Ȃ��I");
			ScreenFlip();
		}
		break;
	}
}

int KANOJOGS::answer()
{
	int startFinalRead = 44;
	int readNumber = 6;
	int answer;
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