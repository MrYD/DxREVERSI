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
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetWindowSizeChangeEnableFlag(TRUE);
    unique_ptr<DXBoard> board(new DXBoard());
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		// 画面を初期化
		ClearDrawScreen();
		// 描画先画面を裏にする
		SetDrawScreen(DX_SCREEN_BACK);
		board->face();
		// 裏画面の内容を表画面に反映します
		ScreenFlip();
	}
	WaitKey();
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}