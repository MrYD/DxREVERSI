#include "DXBoard.h"
#include "AI.h"

DXBoard::DXBoard()
{
	this->init();
}

DXBoard::~DXBoard()
{
}
void DXBoard::init()
{
	mode = 0;
	isEnd = false;
	Board::init(1);
}

void DXBoard::print()
{
	// 画面を初期化
	ClearDrawScreen();
	// 描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);
	printBoard();
	printBotans();
	// 裏画面の内容を表画面に反映します
	ScreenFlip();
}
void DXBoard::printBotans()
{
	DrawCircle(100, 35, 17, BLACK, TRUE);
	DrawCircle(100, 75, 17, WHITE, TRUE);
	DrawFormatString(140, 35, BLACK, "%d", getNumber(1));
	DrawFormatString(140, 75, BLACK, "%d", getNumber(2));
	LoadGraphScreen(450, 80, "C:\\Users\\MOD\\Documents\\Visual Studio 2013\\Projects\\REVERSI\\REVERSI\\画像\\UNDO.png", TRUE);
	LoadGraphScreen(450, 150, "C:\\Users\\MOD\\Documents\\Visual Studio 2013\\Projects\\REVERSI\\REVERSI\\画像\\MENU.png", TRUE);
	DrawFormatString(340, 75, BLACK, "TURN %d", getThisTurn());

}
void DXBoard::printBoard()
{
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
			if (log[thisTurn][i][j] == 1)
			{
				DrawCircle(100 + i * 40, 120 + j * 40, 17, BLACK, TRUE);
			}
			if (log[thisTurn][i][j] == 2)
			{
				DrawCircle(100 + i * 40, 120 + j * 40, 17, WHITE, TRUE);
			}
			if (ableSpace[i][j] != 0 && turnPlayer == 1)
			{
				DrawCircle(100 + i * 40, 120 + j * 40, 17, LIGHT_BLACK, TRUE);
			}
			if (ableSpace[i][j] != 0 && turnPlayer == 2)
			{
				DrawCircle(100 + i * 40, 120 + j * 40, 17, LIGHT_WHITE, TRUE);
			}
		}
	}
	if (getCondition() == 0 && turnPlayer == 2)
	{
		DrawCircle(100 + point[thisTurn].get_x() * 40, 120 + point[thisTurn].get_y() * 40, 2,WHITE, TRUE);
	}
	if (getCondition() == 0 && turnPlayer == 1)
	{
		DrawCircle(100 + point[thisTurn].get_x() * 40, 120 + point[thisTurn].get_y() * 40, 2, BLACK, TRUE);
	}
}
void DXBoard::result_MessageBox()
{
	int flag;
	if ((getNumber(1) > getNumber(2) && mode == 2) || (getNumber(1) < getNumber(2) && mode == 3))
	{
		flag = MessageBox(
			NULL,
			TEXT("YOU WIN !"),
			TEXT("RESULT"),
			MB_YESNO | MB_ICONQUESTION);
	}
	else if ((getNumber(1) < getNumber(2) && mode == 2) || (getNumber(1) > getNumber(2) && mode == 3))
	{
		flag = MessageBox(
			NULL,
			TEXT("YOU LOSE!"),
			TEXT("RESULT"),
			MB_YESNO | MB_ICONQUESTION);
	}
	else if (getNumber(1) > getNumber(2))
	{
		flag = MessageBox(
			NULL,
			TEXT("PLAYER 1 WIN!"),
			TEXT("RESULT"),
			MB_YESNO | MB_ICONQUESTION);
	}
	else if (getNumber(1) < getNumber(2))
	{
		flag = MessageBox(
			NULL,
			TEXT("PLAYER 2 WIN!"),
			TEXT("RESULT"),
			MB_YESNO | MB_ICONQUESTION);
	}
	else if (getNumber(1) == getNumber(2))
	{
		flag = MessageBox(
			NULL,
			TEXT("DRAW!"),
			TEXT("RESULT"),
			MB_YESNO | MB_ICONQUESTION);
	}
	if (flag == IDNO)
	{
		undo();
		if (mode != 1)
		{
			undo();
		}
		return;
	}
	isEnd = true;
}

void DXBoard::pass_MessageBox()
{
	int flag;
	flag = MessageBox(
		NULL,
		TEXT("PASS ?"),
		TEXT("REVERSI"),
		MB_YESNO | MB_ICONQUESTION);
	if (flag != IDNO)
	{
		pass();
		print();
	}
	else
	{
		undo();
		if (mode != 1)
		{
			undo();
		}
		print();
	}
}
void DXBoard::menu_MessageBox()
{
	int flag;
	flag = MessageBox(
		NULL,
		TEXT("END THIS GAME ?"),
		TEXT("REVERSI"),
		MB_YESNO | MB_ICONQUESTION);
	if (flag != IDNO)
	{
		this->init();
		menu();
	}
	return;
}

void DXBoard::menu()
{
	if (mode != 0)
	{
		return;
	}
	ClearDrawScreen();
	LoadGraphScreen(150, 100, "C:\\Users\\MOD\\Documents\\Visual Studio 2013\\Projects\\REVERSI\\REVERSI\\画像\\REVERCI_title.png", TRUE);
	LoadGraphScreen(50, 350, "C:\\Users\\MOD\\Documents\\Visual Studio 2013\\Projects\\REVERSI\\REVERSI\\画像\\2PLAYER.png", TRUE);
	LoadGraphScreen(250, 350, "C:\\Users\\MOD\\Documents\\Visual Studio 2013\\Projects\\REVERSI\\REVERSI\\画像\\BLACK.png", TRUE);
	LoadGraphScreen(450, 350, "C:\\Users\\MOD\\Documents\\Visual Studio 2013\\Projects\\REVERSI\\REVERSI\\画像\\WHITE.png", TRUE);
	ScreenFlip();
	int ClickX, ClickY, Button;
	int Flag = FALSE, i, j;
	if (GetMouseInputLog(&Button, &ClickX, &ClickY, TRUE) == 0)
	{
		// 左ボタンがクリックされていたらフラグを立てて、座標も保存する
		if ((Button & MOUSE_INPUT_LEFT) != 0)
		{
			Flag = TRUE;
			i = ClickX;
			j = ClickY;
		}
	}
	//フラグが立っていたら
	if (Flag == TRUE)
	{
		if (i >= 50 && i <= 200 && j >= 350 && j <= 400)
		{
			mode = 1;
		}
		if (i >= 250 && i <= 400 && j >= 350 && j <= 400)
		{
			mode = 2;
		}
		if (i >= 450 && i <= 600 && j >= 350 && j <= 400)
		{
			mode = 3;
		}
	}
}

void DXBoard::input(int* num, int* i, int* j)
{
	if ((mode == 2 && turnPlayer == 2) || (mode == 3 && turnPlayer == 1))
	{
		*num = 0;
		return;
	}
	int ClickX, ClickY, Button;
	if (GetMouseInputLog(&Button, &ClickX, &ClickY, TRUE) == 0)
	{
		if ((Button & MOUSE_INPUT_LEFT) != 0)
		{
			if (ClickX >= 450 && ClickX <= 600 && ClickY >= 80 && ClickY <= 130)
			{
				*num = -1;
				return;
			}
			if (ClickX >= 450 && ClickX <= 600 && ClickY >= 150 && ClickY <= 200)
			{
				menu_MessageBox();
				return;
			}
			if (ClickX >= 80 && ClickX <= 400 && ClickY >= 100 && ClickY <= 420 && isEnd == false)
			{
				*num = 1;
				*i = (ClickX - 80) / 40;
				*j = (ClickY - 100) / 40;
				return;
			}
		}
	}
	*num = 99;
}


void DXBoard::getBoard()
{
	if (mode == 0)
	{
		return;
	}
	print();
	switch (getCondition())
	{
	case 0:

		int num, i, j;
		input(&num, &i, &j);
		switch (num)
		{
		default:
			return;
		case 1:
		{
				  Point *point = new Point(i, j, 0);
				  if (put(*point))
				  {
					  print();
				  }
				  delete point;
				  return;
		}
		case -1:
			undo();
			if (mode != 1)
			{
				undo();
			}
			print();
			return;
		case 0:
		{
				  Point *point = new Point(AI::answer(this), ableSpace);
				  if (put(*point))
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
		input(&num, &i, &j);
		return;
	}
}