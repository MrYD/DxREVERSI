#include "GameScreen.h"
GameScreen::GameScreen()
{
}
GameScreen::GameScreen(int* screenMode, int mode, Board *board)
{
	this->screenMode = screenMode;
	init(mode, board);
}

GameScreen::~GameScreen()
{
	for (int i = 0; i < 9; i++)
	{
		delete botan[i];
	}
}
int GameScreen::getMode()
{
	return mode;
}
void GameScreen::init(int mode, Board *board)
{
	this->mode = mode;
	this->board = board;
	this->message = BEGIN;
	isEnd = false;
	isStart = false;
	botan[0] = new Botan(0, 0, 0, 0, "..\\REVERSI\\画像\\背景1.png");
	botan[1] = new Botan(200, 240, 320, 320, "..\\REVERSI\\画像\\BOARD.png"); //boad
	botan[2] = new Botan(0, 0, 240, 200, "");
	botan[3] = new Botan(240, 0, 360, 200, "");
	botan[4] = new Botan(600, 240, 60, 152, "..\\REVERSI\\画像\\UNDO.png");
	botan[5] = new Botan(680, 240, 60, 152, "..\\REVERSI\\画像\\MENU.png");
	botan[7] = new Botan(0, 0, 40, 40, "..\\REVERSI\\画像\\KAGE_WHITE.png");
	botan[6] = new Botan(0, 0, 40, 40, "..\\REVERSI\\画像\\KAGE_BLACK.png");
	botan[8] = new Botan(200 + 121, 240 + 121, 80, 80, "..\\REVERSI\\画像\\START.png");
}

void GameScreen::face()
{
	todo = 999999, i = 0, j = 0;
	input();
	if (!isStart)
	{
		return;
	}
	switch (board->getCondition())
	{
	case 0:
		switch (todo)
		{
		default:
			if ((mode == STBLACK && board->getTurnPlayer() == 1) || (mode == STWHITE && board->getTurnPlayer() == 2))
			{
				message = PLAYER;
			}
			return;
		case 1: //プレーヤーのターン
		{
					Point *point = new Point(i, j, 0);
					board->put(*point);
					delete point;
					message = NON;
					return;
		}
		case 2: //モード４
			if (board->getTurnPlayer() == 1)
			{
				if (message != CPUA)
				{
					message = CPUA;
					return;
				}
				Point *point = new Point(AI::answerA(*board), board->ableSpace);
				board->put(*point);
				message = NON;
				delete point;
				return;
			}
			else
			{
				if (message != CPUB)
				{
					message = CPUB;
					return;
				}
				Point *point = new Point(AI::answerA(*board), board->ableSpace);
				board->put(*point);
				message = NON;
				delete point;
				return;
			}

		case -1: //待った
			board->undo();
			if (mode != TWOPLAYER)
			{
				board->undo();
			}
			return;
		case 0: //cpuのターン
		{
					if (message != CPU)
					{
						message = CPU;
						return;
					}
					board->put(ans);
					message = NON;
					return;
		}
		}
	case 4:
		if (message != PASS)
		{
			message = PASS;
			return;
		}
		pass_MessageBox();
		message = NON;
		return;
	default:
		if (!isEnd)
		{
			if (message != END)
			{
				message = END;
				return;
			}
			result_MessageBox();
		}
		return;
	}
}

void GameScreen::input()
{
	if (isStart && !isEnd)
	{
		if (mode == 4)
		{
			todo = 2;
			return;
		}
		if ((mode == STBLACK && board->getTurnPlayer() == 2) || (mode == STWHITE && board->getTurnPlayer() == 1))
		{
			todo = 0;
			return;
		}
	}
	int ClickX, ClickY, Button;
	if (GetMouseInputLog(&Button, &ClickX, &ClickY, TRUE) == 0)
	{

		if ((Button & MOUSE_INPUT_LEFT) != 0)
		{

			if (botan[8]->isTouched(ClickX, ClickY) && isStart == false)
			{
				isStart = true;
				return;
			}
			if (botan[4]->isTouched(ClickX, ClickY))
			{
				todo = -1;
				return;
			}
			if (botan[5]->isTouched(ClickX, ClickY))
			{
				menu_MessageBox();
				return;
			}
			if (botan[1]->isTouched(ClickX, ClickY) && !isEnd)
			{
				todo = 1;
				i = (ClickX - botan[1]->getX()) / 40;
				j = (ClickY - botan[1]->getY()) / 40;
				return;
			}
		}
	}

}

void GameScreen::print()
{
	if (!isStart)
	{
		printPre();
	}
	if (isStart)
	{
		printGame();
	}
}
void GameScreen::printGame()
{
	int MouseX, MouseY;
	GetMousePoint(&MouseX, &MouseY);
	botan[0]->print();
	botan[1]->printWhite();
	botan[2]->print();
	botan[3]->print();
	if (isEnd){
		botan[4]->printWhite();
	}
	else {
		botan[4]->print(MouseX, MouseY);
	}
	botan[5]->print(MouseX, MouseY);
	int x = botan[1]->getX();
	int y = botan[1]->getY();
	for (int i = 0; i < 9; i++)
	{
		DrawLine(x, y + 40 * i, x + 320, y + 40 * i, BLACK);
		DrawLine(x + 40 * i, y, x + 40 * i, y + 320, BLACK);
	}
	DrawCircle(x + 80, y + 80, 2, BLACK, TRUE);
	DrawCircle(x + 240, y + 80, 2, BLACK, TRUE);
	DrawCircle(x + 80, y + 240, 2, BLACK, TRUE);
	DrawCircle(x + 240, y + 240, 2, BLACK, TRUE);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board->log[board->getThisTurn()][i][j] == 1)
			{
				DrawCircle(x + 20 + i * 40, y + 20 + j * 40, 17, BLACK, TRUE);
			}
			if (board->log[board->getThisTurn()][i][j] == 2)
			{
				DrawCircle(x + 20 + i * 40, y + 20 + j * 40, 17, WHITE, TRUE);
			}
			if (board->ableSpace[i][j] != 0 && board->getTurnPlayer() == 1)
			{
				botan[6]->printAt(x + i * 40, y + j * 40, MouseX, MouseY, 50);
			}
			if (board->ableSpace[i][j] != 0 && board->getTurnPlayer() == 2)
			{
				botan[7]->printAt(x + i * 40, y + j * 40, MouseX, MouseY, -50);
			}
		}
	}
	if (board->getCondition() == 0 && board->getTurnPlayer() == 2 && board->getThisTurn() != 0)
	{
		DrawCircle(x + 20 + board->point[board->getThisTurn()].get_x() * 40, y + 20 + board->point[board->getThisTurn()].get_y() * 40, 2, WHITE, TRUE);
	}
	if (board->getCondition() == 0 && board->getTurnPlayer() == 1 && board->getThisTurn() != 0)
	{
		DrawCircle(x + 20 + board->point[board->getThisTurn()].get_x() * 40, y + 20 + board->point[board->getThisTurn()].get_y() * 40, 2, BLACK, TRUE);
	}
	DrawCircle(100, 260, 17, BLACK, TRUE);
	DrawCircle(100, 300, 17, WHITE, TRUE);
	DrawFormatString(140, 260, BLACK, "%d", board->getNumber(1));
	DrawFormatString(140, 300, BLACK, "%d", board->getNumber(2));
	DrawFormatString(85, 340, BLACK, "TURN  %d", board->getThisTurn());
}

void GameScreen::printPre()
{
	int MouseX, MouseY;
	GetMousePoint(&MouseX, &MouseY);
	botan[0]->print();
	botan[1]->printWhite();
	botan[2]->printWhite();
	botan[3]->printWhite();
	botan[4]->printWhite();
	botan[5]->print(MouseX, MouseY);
	int x = botan[1]->getX();
	int y = botan[1]->getY();
	for (int i = 0; i < 9; i++)
	{
		DrawLine(x, y + 40 * i, x + 320, y + 40 * i, BLACK);
		DrawLine(x + 40 * i, y, x + 40 * i, y + 320, BLACK);
	}
	DrawCircle(x + 80, y + 80, 2, BLACK, TRUE);
	DrawCircle(x + 240, y + 80, 2, BLACK, TRUE);
	DrawCircle(x + 80, y + 240, 2, BLACK, TRUE);
	DrawCircle(x + 240, y + 240, 2, BLACK, TRUE);

	if (board->getCondition() == 0 && board->getTurnPlayer() == 2 && board->getThisTurn() != 0)
	{
		DrawCircle(x + 20 + board->point[board->getThisTurn()].get_x() * 40, y + 20 + board->point[board->getThisTurn()].get_y() * 40, 2, WHITE, TRUE);
	}
	if (board->getCondition() == 0 && board->getTurnPlayer() == 1 && board->getThisTurn() != 0)
	{
		DrawCircle(x + 20 + board->point[board->getThisTurn()].get_x() * 40, y + 20 + board->point[board->getThisTurn()].get_y() * 40, 2, BLACK, TRUE);
	}
	DrawCircle(100, 260, 17, BLACK, TRUE);
	DrawCircle(100, 300, 17, WHITE, TRUE);
	DrawFormatString(140, 260, BLACK, "%d", board->getNumber(1));
	DrawFormatString(140, 300, BLACK, "%d", board->getNumber(2));
	DrawFormatString(85, 340, BLACK, "TURN  %d", board->getThisTurn());
	botan[8]->print(MouseX, MouseY);
}
void GameScreen::result_MessageBox()
{
	int flag;
	if ((board->getNumber(1) > board->getNumber(2) && mode == STBLACK) || (board->getNumber(1) < board->getNumber(2) && mode == STWHITE))
	{
		flag = MessageBox(
			NULL,
			TEXT("接待失敗!"),
			TEXT("RESULT"),
			MB_YESNO | MB_ICONQUESTION);
	}
	else if ((board->getNumber(1) < board->getNumber(2) && mode == STBLACK) || (board->getNumber(1) > board->getNumber(2) && mode == STWHITE))
	{
		flag = MessageBox(
			NULL,
			TEXT("接待成功!"),
			TEXT("RESULT"),
			MB_YESNO | MB_ICONQUESTION);
	}
	else if (board->getNumber(1) > board->getNumber(2))
	{
		flag = MessageBox(
			NULL,
			TEXT("PLAYER 1 WIN!"),
			TEXT("RESULT"),
			MB_YESNO | MB_ICONQUESTION);
	}
	else if (board->getNumber(1) < board->getNumber(2))
	{
		flag = MessageBox(
			NULL,
			TEXT("PLAYER 2 WIN!"),
			TEXT("RESULT"),
			MB_YESNO | MB_ICONQUESTION);
	}
	else if (board->getNumber(1) == board->getNumber(2))
	{
		flag = MessageBox(
			NULL,
			TEXT("パーフェクト接待!"),
			TEXT("RESULT"),
			MB_YESNO | MB_ICONQUESTION);
	}
	if (flag == IDNO)
	{
		board->undo();
		if (mode != TWOPLAYER)
		{
			board->undo();
		}
		message = NON;
		return;
	}
	isEnd = true;
}

void GameScreen::pass_MessageBox()
{
	int flag;
	flag = MessageBox(
		NULL,
		TEXT("パスです。"),
		TEXT("REVERSI"),
		MB_YESNO | MB_ICONQUESTION);
	if (flag != IDNO)
	{
		board->pass();
		print();
	}
	else
	{
		board->undo();
		if (mode != TWOPLAYER)
		{
			board->undo();
		}
		print();
	}
}
void GameScreen::menu_MessageBox()
{
	int flag;
	flag = MessageBox(
		NULL,
		TEXT("ゲームを中断し、メニューに戻りますか?"),
		TEXT("REVERSI"),
		MB_YESNO | MB_ICONQUESTION);
	if (flag != IDNO)
	{
		*screenMode = 0;
	}
	return;
}