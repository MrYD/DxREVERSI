#include "GameScreen.h"


GameScreen::GameScreen()
{
}
GameScreen::GameScreen(int* mode,Board *board)
{
	init(mode,board);
}


GameScreen::~GameScreen()
{
}
int GameScreen::getMode()
{
	return *mode;
}
void GameScreen::init(int* mode,Board *board)
{
	this->mode = mode;
	this->board = board;
	isEnd = false;
	botan[0] = Botan(450, 80, 150, 50, "..\\REVERSI\\画像\\UNDO.png");
	botan[1] = Botan(450, 150, 150, 50, "..\\REVERSI\\画像\\MENU.png");
}

void GameScreen::face()
{
	print();
	switch (board->getCondition())
	{
	case 0:
		todo = 99, i = 0, j = 0;
		input();
		switch (todo)
		{
		default:
			DrawFormatString(460, 240, BLACK, "TURN PLAYER %d", board->getTurnPlayer());
			ScreenFlip();
			return;
		case 1: //プレーヤーのターン
		{
				  Point *point = new Point(i, j, 0);
				  if (board->put(*point))
				  {
					  print();
				  }
				  delete point;
				  return;
		}
		case 2: //モード４
			if (board->getTurnPlayer() == 1)
			{
				DrawFormatString(460, 240, BLACK, "TURN CPU A");
				ScreenFlip();
				Point *point = new Point(AI::answerA(*board), board->ableSpace);
				if (board->put(*point))
				{
					print();
				}
				delete point;
				return;
			}
			else
			{
				DrawFormatString(460, 240, BLACK, "TURN CPU B");
				ScreenFlip();
				Point *point = new Point(AI::answerB(*board), board->ableSpace);
				if (board->put(*point))
				{
					print();
				}
				delete point;
				return;
			}
			
		case -1: //待った
			board->undo();
			if (*mode != 1)
			{
				board->undo();
			}
			print();
			return;
		case 0: //cpuのターン
		{
				  DrawFormatString(460, 240, BLACK, "TURN CPU");
				  ScreenFlip();
				  Point *point = new Point(AI::answer(board), board->ableSpace);
				  if (board->put(*point))
				  {
					  print();
				  }
				  delete point;
				  return;
		}
		}

	case 4:
		pass_MessageBox();
		return;
	default:
		if (isEnd == false)
		{
			result_MessageBox();
		}
		input();
		return;
	}
}

void GameScreen::input()
{
	if ((*mode == 2 && board->getTurnPlayer() == 2) || (*mode == 3 && board->getTurnPlayer() == 1))
	{
		todo = 0;
		return;
	}
	if (*mode == 4)
	{
		todo = 2;
	}
	int ClickX, ClickY, Button;
	if (GetMouseInputLog(&Button, &ClickX, &ClickY, TRUE) == 0)
	{
		if ((Button & MOUSE_INPUT_LEFT) != 0)
		{
			if (botan[0].isTouched(ClickX, ClickY))
			{
				todo = -1;
				return;
			}
			if (botan[1].isTouched(ClickX, ClickY))
			{
				menu_MessageBox();
				return;
			}
			if (ClickX >= 80 && ClickX <= 400 && ClickY >= 100 && ClickY <= 420 && isEnd == false)
			{
				todo = 1;
				i = (ClickX - 80) / 40;
				j = (ClickY - 100) / 40;
				return;
			}
		}
	}
}

void GameScreen::print()
{
	for (int i = 0; i < 2; i++)
	{
		botan[i].print();
	}
	DrawBox(80, 100, 400, 420, BOARD, TRUE);
	for (int i = 0; i < 9; i++)
	{
		DrawLine(80, 100 + 40 * i, 400, 100 + 40 * i, BLACK);
		DrawLine(80 + 40 * i, 100, 80 + 40 * i, 420, BLACK);
	}
	DrawCircle(80 + 80, 100 + 80, 2, BLACK, TRUE);
	DrawCircle(80 + 240, 100 + 80, 2, BLACK, TRUE);
	DrawCircle(80 + 80, 100 + 240, 2, BLACK, TRUE);
	DrawCircle(80 + 240, 100 + 240, 2, BLACK, TRUE);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board->log[board->getThisTurn()][i][j] == 1)
			{
				DrawCircle(100 + i * 40, 120 + j * 40, 17, BLACK, TRUE);
			}
			if (board->log[board->getThisTurn()][i][j] == 2)
			{
				DrawCircle(100 + i * 40, 120 + j * 40, 17, WHITE, TRUE);
			}
			if (board->ableSpace[i][j] != 0 && board->getTurnPlayer() == 1)
			{
				DrawCircle(100 + i * 40, 120 + j * 40, 17, LIGHT_BLACK, TRUE);
			}
			if (board->ableSpace[i][j] != 0 && board->getTurnPlayer() == 2)
			{
				DrawCircle(100 + i * 40, 120 + j * 40, 17, LIGHT_WHITE, TRUE);
			}
		}
	}
	if (board->getCondition() == 0 && board->getTurnPlayer() == 2)
	{
		DrawCircle(100 + board->point[board->getThisTurn()].get_x() * 40, 120 + board->point[board->getThisTurn()].get_y() * 40, 2, WHITE, TRUE);
	}
	if (board->getCondition() == 0 && board->getTurnPlayer() == 1)
	{
		DrawCircle(100 + board->point[board->getThisTurn()].get_x() * 40, 120 + board->point[board->getThisTurn()].get_y() * 40, 2, BLACK, TRUE);
	}
	DrawCircle(100, 35, 17, BLACK, TRUE);
	DrawCircle(100, 75, 17, WHITE, TRUE);
	DrawFormatString(140, 35, BLACK, "%d", board->getNumber(1));
	DrawFormatString(140, 75, BLACK, "%d", board->getNumber(2));
	DrawFormatString(340, 75, BLACK, "TURN %d", board->getThisTurn());
	DrawBox(440, 220, 620, 420, BLACK, FALSE);
}

void GameScreen::result_MessageBox()
{
	int flag;
	if ((board->getNumber(1) > board->getNumber(2) && *mode == 2) || (board->getNumber(1) < board->getNumber(2) && *mode == 3))
	{
		flag = MessageBox(
			NULL,
			TEXT("YOU WIN !"),
			TEXT("RESULT"),
			MB_YESNO | MB_ICONQUESTION);
	}
	else if ((board->getNumber(1) < board->getNumber(2) && *mode == 2) || (board->getNumber(1) > board->getNumber(2) && *mode == 3))
	{
		flag = MessageBox(
			NULL,
			TEXT("YOU LOSE!"),
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
			TEXT("DRAW!"),
			TEXT("RESULT"),
			MB_YESNO | MB_ICONQUESTION);
	}
	if (flag == IDNO)
	{
		board->undo();
		if (*mode != 1)
		{
			board->undo();
		}
		return;
	}
	isEnd = true;
}

void GameScreen::pass_MessageBox()
{
	int flag;
	flag = MessageBox(
		NULL,
		TEXT("PASS ?"),
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
		if (*mode != 1)
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
		TEXT("END THIS GAME ?"),
		TEXT("REVERSI"),
		MB_YESNO | MB_ICONQUESTION);
	if (flag != IDNO)
	{
		*mode = 0;
	}
	return;
}