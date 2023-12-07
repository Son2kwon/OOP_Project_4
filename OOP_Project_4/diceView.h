#pragma once
#include<iostream>
#include<iostream>
#include<Windows.h>
#include<string>

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

		
		if (kept == x) {

			if (x == false)
				Sleep(500);

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
			keep(kept);			//�ֻ��� ��� �Ʒ� keep ǥ�� ������Ʈ

		}
	

		

	}


	void keep(boolean b) {		//keep ���� ����, ȭ�鿡 ǥ��
		if (kept = b) {
			gotoxy(startX, startY + 3);
			cout << "keep";
		}
		else {
			gotoxy(startX, startY + 3);
			cout << "    ";
		}
		
	}



	void  gotoxy(int x, int y) {		//Ŀ�� ��ǥ �̵� (��� �ֻ����� ���� ���µ� ���ο� ���Ͽ� ���� �����Ϸ��ϱ� ��������..�Ф�)
		COORD Cur;
		Cur.X = x;
		Cur.Y = y;
		 
		

		/*if (SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur) == 0) {
			if (Cur.X < 0 || Cur.X >= csbi.dwSize.X || Cur.Y < 0 || Cur.Y >= csbi.dwSize.Y) {
				return "invalid pos" + to_string(Cur.X) + "," + to_string(Cur.Y)+"/"+to_string(csbi.dwSize.X)+","+to_string(csbi.dwSize.Y);
			}
			string str = to_string(Cur.X)+","+to_string(Cur.Y);
			return str;

		}
		return  to_string(Cur.X) + "," + to_string(Cur.Y) + "/" + to_string(csbi.dwSize.X) + "," + to_string(csbi.dwSize.Y);*/
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	}
	void ClearScrollback() { cout << "\x1B[0J"; }	//���� Ŀ�� ��ġ���� ȭ�� ������ ����� �޼ҵ�
};


