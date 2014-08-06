#include <iostream>
#include<memory>
#include"Board.h"
#include "DxLib.h"
#include"DXBoard.h"
using namespace std;

//int main()
//{
//	unique_ptr<GameBoard> board(new GameBoard());
//	while (board->doTurn());
//	int a;
//	cin >> a;
//	return 0;
//}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetBackgroundColor(250, 250, 250);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	SetWindowSizeChangeEnableFlag(TRUE);
    unique_ptr<DXBoard> board(new DXBoard());
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		board->menu();
		board->getBoard();
	}
	WaitKey();
	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}