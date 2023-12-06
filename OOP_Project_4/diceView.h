#pragma once
#include<iostream>
#include<iostream>
#include<Windows.h>

using namespace std;

class diceView {			//diceView Ŭ������ �ܼ�â�� ��Ÿ���� �ֻ��� ��翡 ���� Ŭ����.

private:
	int startX;	//��ġ 
	int startY;
	int number;//��
	boolean kept = false;//���� ����

public:
	void setNum(int n) {		//�ֻ��� �� ����
		number = n;
	}
	void setPos(int x, int y) {		//��ġ �ʱ�ȭ
		startX = x;
		startY = y;
	}

	void drawDice(boolean x) {		//�ֻ����� ȭ�鿡 �׸�. �Ű����� x: true-> �� �ֻ����� ����� �ֻ����� �ֻ��� �׸�.

		if (x == false)
			Sleep(100);
		if (kept == x) {
			gotoxy(startX, startY);
			cout << "��";
			for (int j = 0; j < 3; j++)
				cout << "��";
			cout << "��\n";

			gotoxy(startX, startY + 1);
			cout << "��";
			cout.width(3);
			cout << number;
			cout << "��\n";

			gotoxy(startX, startY + 2);
			cout << "��";
			for (int j = 0; j < 3; j++)
				cout << "��";
			cout << "��";
		}
		if(x==false)
			Sleep(500);

		

	}


	void keep(boolean keep) {		//keep ���� ����.
		kept = keep;
	}



	void gotoxy(int x, int y) {		//Ŀ�� ��ǥ �̵� (��� �ֻ����� ���� ���µ� ���ο� ���Ͽ� ���� �����Ϸ��ϱ� ��������..�Ф�)
		COORD Cur;
		Cur.X = x;
		Cur.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	}
	void ClearScrollback() { cout << "\x1B[0J"; }	//���� Ŀ�� ��ġ���� ȭ�� ������ ����� �޼ҵ�
};


