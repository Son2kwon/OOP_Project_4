#pragma once
#include<iostream>
#include<iostream>
#include<Windows.h>
#include<string>

using namespace std;

class diceView {			//diceView 클래스는 콘솔창에 나타나는 주사위 모양에 대한 클래스.

private:
	int startX;	//위치 
	int startY;
	int number;//눈
	boolean kept = false;//저장 여부

public:
	void setNum(int n) {		//주사위 눈 설정
		number = n;
	}
	void setPos(int x, int y) {		//위치 초기화
		startX = x;
		startY = y;
	}

	void drawDice(boolean x) {		//주사위를 화면에 그림. 매개변수 x: true-> 이 주사위가 저장된 주사위면 주사위 그림.

		
		if (kept == x) {

			if (x == false)
				Sleep(500);

			gotoxy(startX, startY);
			cout << "┌";
			for (int j = 0; j < 3; j++)
				cout << "─";
			cout << "┐\n";

			gotoxy(startX, startY + 1);
			cout << "│";
			cout.width(3);
			cout << number;
			cout << "│\n";

			gotoxy(startX, startY + 2);
			cout << "└";
			for (int j = 0; j < 3; j++)
				cout << "─";
			cout << "┘";
			keep(kept);			//주사위 모양 아래 keep 표시 업데이트

		}
	

		

	}


	void keep(boolean b) {		//keep 상태 설정, 화면에 표시
		if (kept = b) {
			gotoxy(startX, startY + 3);
			cout << "keep";
		}
		else {
			gotoxy(startX, startY + 3);
			cout << "    ";
		}
		
	}



	void  gotoxy(int x, int y) {		//커서 좌표 이동 (사실 주사위랑 관련 없는데 새로운 파일에 따로 정의하려니까 오류나서..ㅠㅠ)
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
	void ClearScrollback() { cout << "\x1B[0J"; }	//현재 커서 위치부터 화면 끝까지 지우는 메소드
};


