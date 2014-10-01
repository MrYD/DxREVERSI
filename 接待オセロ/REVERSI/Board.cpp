#include "Board.h"
#include "AI.h"
#include<iostream>
#include<memory>
#include<time.h>
using namespace std;


Board::Board(int firstPlayer)
{
	init(firstPlayer);
}
Board::Board()
{
}
Board::~Board()
{
}
void Board::init(int firstPlayer)
{
	thisTurn = 0;
	this->turnPlayer = firstPlayer;
	clear(log[thisTurn]);
	log[thisTurn][3][3] = 1;
	log[thisTurn][3][4] = 2;
	log[thisTurn][4][3] = 2;
	log[thisTurn][4][4] = 1;
	setAbleSpace();
}

void Board::clear(int arr[8][8])
{
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
		arr[i][j] = 0;
}
int Board::oponent(int player)
{
	if (player == 1) return 2;
	else if (player == 2) return 1;
	else return 0;
}
bool Board::isAble(int fu[8][8], Point point, int t)
{
	int i = point.get_x();
	int j = point.get_y();
	int a = oponent(t);
	int count;
	int check;
	if (fu[i][j] == 0) 
	{
		count = 0;    //�E�`�F�b�N
		check = a;
		while (check == a && (i + count)< 7)
		{
			count++;
			check = fu[i + count][j];
		}
		if (check == t && count > 1)
		{
			return true;
		}

		count = 0; // ���`�F�b�N
		check = a;
		while (check == a && 0 < (i - count))
		{
			count++;
			check = fu[i - count][j];
		}
		if (check == t && count > 1)
		{
			return true;
		}

		count = 0; //��`�F�b�N
		check = a;
		while (check == a && 0 < (j - count))
		{
			count++;
			check = fu[i][j - count];
		}
		if (check == t && count > 1)
		{
			return true;
		}

		count = 0;  //���`�F�b�N
		check = a;
		while (check == a && (j + count) <7)
		{
			count++;
			check = fu[i][j + count];
		}
		if (check == t && count > 1)
		{
			return true;
		}

		count = 0; //�E���`�F�b�N
		check = a;
		while (check == a && (i + count) < 7 && (j + count) <7)
		{
			count++;
			check = fu[i + count][j + count];
		}
		if (check == t && count > 1)
		{
			return true;
		}
		count = 0; //�����`�F�b�N
		check = a;
		while (check == a && 0 < (i - count) && (j + count)<7)
		{
			count++;
			check = fu[i - count][j + count];
		}
		if (check == t && count > 1)
		{
			return true;
		}
		count = 0;  //�E��`�F�b�N
		check = a;
		while (check == a && (i + count) < 7 && 0 < (j - count))
		{
			count++;
			check = fu[i + count][j - count];
		}
		if (check == t && count > 1)
		{
			return true;
		}

		count = 0; //�E��`�F�b�N
		check = a;
		while (check == a && 0 < (i - count) && 0 <(j - count))
		{
			count++;
			check = fu[i - count][j - count];

		}
		if (check == t && count > 1)
		{
			return true;
		}
	}
	return false;
}

int Board::put(Point point)
{
	if (ableSpace[point.get_x()][point.get_y()] == 0)
	{
		return false;
	}
	int count, check, num = 0;
	int i = point.get_x();
	int j = point.get_y();
	int t = turnPlayer;
	int a = oponent(turnPlayer);
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
		log[thisTurn + 1][i][j] = log[thisTurn][i][j];

	log[thisTurn + 1][i][j] = t;
	this->point[thisTurn + 1] = point;

	count = 0;		//�E�`�F�b�N
	check = a;
	while ((check == a) && (i + count< 7))
	{
		count++;
		check = log[thisTurn + 1][i + count][j];
	}
	if (check == t && count > 1)
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i + k][j] = t;
		num++;
	}
	count = 0;		// ���`�F�b�N
	check = a;
	while ((check == a) && (0 < i - count))
	{
		count++;
		check = log[thisTurn + 1][i - count][j];
	}
	if (check == t && count > 1)
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i - k][j] = t;
		num++;
	}
	count = 0;		//��`�F�b�N
	check = a;
	while ((check == a) && (0 < j - count))
	{
		count++;
		check = log[thisTurn + 1][i][j - count];
	}
	if ((check == t) && (count > 1))
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i][j - k] = t;
		num++;
	}
	count = 0;		//���`�F�b�N
	check = a;
	while ((check == a) && (j + count <7))
	{
		count++;
		check = log[thisTurn + 1][i][j + count];
	}
	if ((check == t) && (count > 1))
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i][j + k] = t;
		num++;
	}
	count = 0; //�E���`�F�b�N
	check = a;
	while ((check == a) && (i + count < 7) && (j + count <7))
	{
		count++;
		check = log[thisTurn + 1][i + count][j + count];
	}
	if ((check == t) && (count > 1))
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i + k][j + k] = t;
		num++;
	}
	count = 0; //�����`�F�b�N
	check = a;
	while ((check == a) && (0 < i - count) && (j + count <7))
	{
		count++;
		check = log[thisTurn + 1][i - count][j + count];
	}
	if ((check == t) && (count > 1))
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i - k][j + k] = t;
		num++;
	}

	count = 0;  //�E��`�F�b�N
	check = a;
	while ((check == a) && (i + count < 7) && (0 < j - count))
	{
		count++;
		check = log[thisTurn + 1][i + count][j - count];
	}
	if ((check == t) && (count > 1))
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i + k][j - k] = t;
		num++;
	}
	count = 0; //�E��`�F�b�N
	check = a;
	while ((check == a) && (0 < i - count) && (0 < j - count))
	{
		count++;
		check = log[thisTurn + 1][i - count][j - count];

	}
	if ((check == t) && (count > 1))
	for (int k = 1; k <= count - 1; k++)
	{
		log[thisTurn + 1][i - k][j - k] = t;
		num++;
	}
	if (num != 0)
	{
		nextTurn();
		return num;
	}
	else
		return false;
}
int Board::put(int number)
{
	return put(Point(number, ableSpace));
}
void Board::pass()
{
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
		log[thisTurn + 1][i][j] = log[thisTurn][i][j];
	nextTurn();
}
void Board::undo()
{
	if (thisTurn > 0)
	{
		thisTurn--;
		turnPlayer = oponent(turnPlayer);
	}
	setAbleSpace();
}
void Board::nextTurn()
{
	thisTurn++;
	turnPlayer = oponent(turnPlayer);
	setAbleSpace();
}
int Board::getNumber(int player)
{
	int count = 0;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (log[thisTurn][i][j] == player)
				count++;
		}
	}
	return count;
}
int Board::getAbleNumber(int player)
{
	if (player == getTurnPlayer()) return ableNumber;
	else
	{
		int t = player, a = turnPlayer, count = 0, check = 0, num = 0;
		for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (log[thisTurn][i][j] == 0)
			{
				count = 0;//�E�`�F�b�N
				check = a;
				while (check == a && (i + count)< 7)
				{
					count++;
					check = log[thisTurn][i + count][j];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
				count = 0;// ���`�F�b�N
				check = a;
				while (check == a && 0 < (i - count))
				{
					count++;
					check = log[thisTurn][i - count][j];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
				count = 0; //��`�F�b�N
				check = a;
				while (check == a && 0 < (j - count))
				{
					count++;
					check = log[thisTurn][i][j - count];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
				count = 0; //���`�F�b�N
				check = a;
				while (check == a && (j + count) <7)
				{
					count++;
					check = log[thisTurn][i][j + count];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
				count = 0; //�E���`�F�b�N
				check = a;
				while (check == a && (i + count) < 7 && (j + count) <7)
				{
					count++;
					check = log[thisTurn][i + count][j + count];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
				count = 0;//�����`�F�b�N
				check = a;
				while (check == a && 0 < (i - count) && (j + count)<7)
				{
					count++;
					check = log[thisTurn][i - count][j + count];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
				count = 0; //�E��`�F�b�N
				check = a;
				while (check == a && (i + count) < 7 && 0 < (j - count))
				{
					count++;
					check = log[thisTurn][i + count][j - count];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
				count = 0;//�E��`�F�b�N
				check = a;
				while (check == a && 0 < (i - count) && 0 <(j - count))
				{
					count++;
					check = log[thisTurn][i - count][j - count];
				}
				if (check == t && count > 1)
				{
					num++;
					continue;
				}
			}
		}
		return num;
	}
}
int Board::getAbleNumber()
{
	return ableNumber;
}
int Board::getThisTurn()
{
	return thisTurn;
}
int Board::getCondition()
{
	return	getCondition(1);
}
int Board::getCondition(int player)
{
	int condition = 0;
	if (getAbleNumber(turnPlayer) == 0)
	{
		condition = 4;
		if (getAbleNumber(oponent(turnPlayer)) == 0)
		{
			int x = getNumber(player);
			int y = getNumber(oponent(player));
			if (x > y) condition = 1;
			if (x < y) condition = 2;
			if (x == y)condition = 3;
		}
	}
	return condition;
}
int Board::getSCondition()
{
	int condition = 0;
	if (getAbleNumber(turnPlayer) == 0)
	{
		if (getAbleNumber(oponent(turnPlayer)) == 0) condition = 5;
		else condition = 4;
	}
	return condition;
}

int Board::getTurnPlayer()
{
	return turnPlayer;
}

void Board::setAbleSpace()
{
	clear(ableSpace);
	int count, check, num = 0;
	int t = turnPlayer;
	int a = oponent(turnPlayer);
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
	{

		if (log[thisTurn][i][j] == 0) {
			count = 0;    //�E�`�F�b�N
			check = a;
			while (check == a && (i + count)< 7)
			{
				count++;
				check = log[thisTurn][i + count][j];
			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}

			count = 0; // ���`�F�b�N
			check = a;
			while (check == a && 0 < (i - count))
			{
				count++;
				check = log[thisTurn][i - count][j];
			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}

			count = 0; //��`�F�b�N
			check = a;
			while (check == a && 0 < (j - count))
			{
				count++;
				check = log[thisTurn][i][j - count];
			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}

			count = 0;  //���`�F�b�N
			check = a;
			while (check == a && (j + count) <7)
			{
				count++;
				check = log[thisTurn][i][j + count];
			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}

			count = 0; //�E���`�F�b�N
			check = a;
			while (check == a && (i + count) < 7 && (j + count) <7)
			{
				count++;
				check = log[thisTurn][i + count][j + count];
			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}
			count = 0; //�����`�F�b�N
			check = a;
			while (check == a && 0 < (i - count) && (j + count)<7)
			{
				count++;
				check = log[thisTurn][i - count][j + count];
			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}
			count = 0;  //�E��`�F�b�N
			check = a;
			while (check == a && (i + count) < 7 && 0 < (j - count))
			{
				count++;
				check = log[thisTurn][i + count][j - count];
			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}

			count = 0; //�E��`�F�b�N
			check = a;
			while (check == a && 0 < (i - count) && 0 <(j - count))
			{
				count++;
				check = log[thisTurn][i - count][j - count];

			}
			if (check == t && count > 1)
			{
				num++;
				ableSpace[i][j] = num;
				continue;
			}
		}
	}

	this->ableNumber = num;
}

GameBoard::GameBoard() :Board(1)
{
	int gameMode;
	cout << "���o�[�V���n�߂܂�.\n\n";
	cout << "player1 vs player2   -1\n";
	cout << "player1 vs     CPU   -2\n";
	cout << "    CPU vs player2   -3\n";
	cout << "\n���[�h��I��ł�������...";
	while (true)
	{
		cin >> gameMode;
		if (!std::cin.fail() && gameMode >= 1 && gameMode <= 3) break;
		cout << "�l���قȂ�܂�." << endl;
		std::cin.clear();    // �G���[�����Z�b�g���܂��B
		std::cin.ignore(1024, '\n');    // �������j�����܂��B
	}
	this->mode = gameMode;
	Board(1);
	print();
}
GameBoard::~GameBoard()
{}
void GameBoard::print()
{
	if (turnPlayer == 1)
	{
		if (thisTurn + 1 < 10)
			cout << " ��0" << thisTurn + 1 << "��    �� ��player1 (" << getNumber(1) << ")\n";
		else
			cout << " ��" << thisTurn + 1 << "��     �� ��player1 (" << getNumber(1) << ")\n";
		cout << "              ��player2 (" << getNumber(2) << ")";
	}
	if (turnPlayer == 2)
	{
		if (thisTurn + 1 < 10)
			cout << " ��0" << thisTurn + 1 << "��       ��player1 (" << getNumber(1) << ")\n";
		else
			cout << " ��" << thisTurn + 1 << "��        ��player1 (" << getNumber(1) << ")\n";
		cout << "           �� ��player2 (" << getNumber(2) << ")";
	}

	for (int i = 0; i < 8; i++){
		cout << endl;
		cout << "    ";
		for (int j = 0; j < 8; j++){
			cout << ston(log[thisTurn][i][j]);
			if (ableSpace[i][j] != 0)
			{
				if (ableSpace[i][j] < 10) cout << " " << ableSpace[i][j];
				else cout << ableSpace[i][j];
			}
			if ((log[thisTurn][i][j] == 0) && (ableSpace[i][j] == 0))
				cout << "�E";
		}
	}
	cout << endl;
}
void GameBoard::printResult()
{

	cout << " �����ʁ�  �@  ��player1 (" << getNumber(1) << ")\n";
	cout << "      �@�@     ��player2 (" << getNumber(2) << ")";

	for (int i = 0; i < 8; i++){
		cout << endl;
		cout << "    ";
		for (int j = 0; j < 8; j++){
			cout << ston(log[thisTurn][i][j]);
			if (ableSpace[i][j] != 0)
			{
				if (ableSpace[i][j] < 10) cout << " " << ableSpace[i][j];
				else cout << ableSpace[i][j];
			}
			if ((log[thisTurn][i][j] == 0) && (ableSpace[i][j] == 0))
				cout << "�E";
		}
	}
	cout << endl;


}
char* GameBoard::ston(int player)
{
	char* ston = NULL;
	if (player == 1)
		ston = "��";
	if (player == 2)
		ston = "��";
	if (player == 0)
		ston = "";
	return ston;
}
bool GameBoard::doTurn()
{

	switch (getCondition())
	{
	case 0:

		int num;
		if ((mode == 2 && turnPlayer == 2) || (mode == 3 && turnPlayer == 1))
			num = 0;
		else
		{
			cout << "�ԍ������...";
			//if (thisTurn+1 < 40)//�̂���n�^�[���܂ŃX�L�b�v
			//{
			//	srand((unsigned)time(NULL));
			//	num = rand() % ableNumber + 1;
			//}
			//else
			{
				while (true)
				{
					cin >> num;
					if (!std::cin.fail() && num >= -2 && num <= getAbleNumber(turnPlayer)) break;
					cout << "�l���قȂ�܂�." << endl;
					std::cin.clear();    // �G���[�����Z�b�g���܂��B
					std::cin.ignore(1024, '\n');    // �������j�����܂��B
				}
			}
		}
		if (num == 0)
		{
			cout << "CPU���l���܂�...";
			num = AI::answerKANOJO(*this);
			//num = 1;
			cout << num << endl;
		}
		if (num == -1)
		{
			cout << "���߂�܂�.\n";
			undo();
			print();
			return true;
		}
		if (num == -2)
		{
			cout << "���߂�܂�.\n";
			undo();
			undo();
			print();
			return true;
		}
		put(num);
		print();
		return true;
	case 4:
		cout << "�u���܂���..." << endl;
		getchar();
		pass();
		print();
		return true;
	case 1:
		printResult();
		if (mode == 3) cout << "\n���� ��CPU�̏��� ����" << flush;
		else cout << "\n������player1�̏�������" << endl;
		return false;
	case 2:
		printResult();
		if (mode == 2) cout << "\n���� ��CPU�̏��� ����" << flush;
		else cout << "\n���� ��player2�̏��� ����" << endl;
		return false;
	case 3:
		printResult();
		cout << "\n���� ���������ł� ����" << endl;
		return false;
	}

}



