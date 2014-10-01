#include "KANOJOGS.h"


KANOJOGS::KANOJOGS(int* screenMod, Board *board) :GameScreen(screenMod,3,board)
{
	exBotan[0] = new Botan(580, 10, 200, 180, "..\\REVERSI\\画像\\KANOJO_s.png");
	exBotan[1] = new Botan(0, 10, 200, 180, "..\\REVERSI\\画像\\吹き出し.png");
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
		DrawFormatString(100, 60, BLACK, "オセロは得意なんだから！");
		ScreenFlip();
		break;
	case CPU:
		if (board->getThisTurn() == 0)
		{
			DrawFormatString(100, 60, BLACK, "私が先ね！");
			ScreenFlip();
			WaitTimer(1000);
		}
		else
		{
			DrawFormatString(100, 60, BLACK, "うーんとね。");
			ScreenFlip();
		}
		break;
	case PLAYER:
		DrawFormatString(100, 60, BLACK, "はいっ、あんたの番よ！");
		ScreenFlip();
		break;
	case PASS:
		DrawFormatString(100, 60, BLACK, "パスね！");
		ScreenFlip();
		break;
	case END:
		if (board->getCondition() == 1)
		{
			DrawFormatString(100, 60, BLACK, "ねっ、強いでしょ！");
			ScreenFlip();
		}
		if (board->getCondition() == 2)
		{
			DrawFormatString(100, 60, BLACK, "ひっどーい！あんたなんか嫌い！！");
			ScreenFlip();
		}
		if (board->getCondition() == 3)
		{
			DrawFormatString(100, 60, BLACK, "あんたもやるじゃない！");
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