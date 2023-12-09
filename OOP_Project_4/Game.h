#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include <conio.h>
#include"Dice.h"
#include"scoreBoard.h"
#include"Turn.h"
#include"diceView.h"
using namespace std;

#define MAXTURN 3	// 한 턴 당 주사위는 3번 굴릴 수 있음
#define NUMOFDICE 5

#define DICEVIEWSTART 3	//커서 이동위치 상수들..
#define STARTPOINT2 21
#define SCORESTART 50

class Game {
private:
	int turn_left;
	vector<ScoreBoard> board;	// 한 사람의 점수판 모임 -> 총 점수판
	Turn turn;
	int numberOfPlayer;	// 총 플레이어 몇 명인지
	int currentPlayer;	// 지금 플레이어가 누구인지 순서 (0, 1, 2, ...)로 표현
	diceView dices[NUMOFDICE];	//diceView는 콘솔창의 주사위 출력을 위한 클래스.

public:
	Game() {	// constructor

	}

	void gameStart() {

		int key;
		cout << "  << Yacht Game >>" << endl << endl;
		cout << "Press Enter to start!!";		//enter 누르면 시작

		while(key=_getch()!=13){}	//enter 키 입력 감지


		// board 초기화
		cout << endl<<endl<<"몇명이 플레이 하시겠습니까?: ";
		cin >> numberOfPlayer;

		//인원수에 따라 board 벡터 초기화
		for (int i = 0; i < numberOfPlayer; i++) {		
			board.push_back(ScoreBoard());
		}
		//모든 점수가 채워질때까지 turnStart 호출
		while (!isGameOver()) {
			turnStart();
		}
		winner();
	}

	void turnStart() {

		initDiceView();		//diceView를 초기화(위치, keep상태)

		int curTurn = 0;	// 총 3번의 기회 중 현재 몇 번 째인가?

		while (curTurn < MAXTURN) {	// 총 3번 굴리는 중
			displayBoard();		//주사위 던질때마다 점수판도 출력되는걸로..
			turn.diceRoll();	// 주사위 굴림
			Sleep(500);

			cout << "[Player " << currentPlayer + 1 << "]" << endl<<endl;
			Sleep(1000);
			
			drawDices();
			

//			1. 나온 주사위를 turn에서 점수 계산 및 출력
//			2. 저장할 주사위의 index를 입력 (1 ~ 5)
//			3. 저장할 주사위를 keep에 저장

			Sleep(600);
			turn.calScore();	// 점수 계산 및 출력
			cout << endl;
			Sleep(600);

			if (curTurn == MAXTURN - 1) break;	// 사실 마지막 기회라면 던지고 끝

			cin.ignore();
			cout << "주사위를 저장하시겠습니까? (y/n): "; char choice; cin >> choice;

			if (choice == 'y') {
				cout << "저장할 주사위를 선택해주세요: ";
				int index_store[5] = { 0, }; int i = 0;	// 0으로 초기화 해두고, 0이 아닌 애들 index만 저장하기
				cin.ignore();
				while (cin >> index_store[i]) {
					i++;
					if (cin.peek() == '\n') { // Check for Enter key
						if (validInput(index_store)) { // 입력이 유효한지 판단하는 함수
							break;
						}
						else {
							cout << "다시 입력하세요." << endl;
							i = 0;
							fill(begin(index_store), end(index_store), 0);
							cin.clear();
							cin.ignore();
							cout << "저장할 주사위를 선택해주세요: ";
							continue;
						}
					}
				}

				turn.storeDice(index_store);	// index를 넘겨 turn에 있는 dice를 저장
				storeDiceView(index_store);		//diceView객체에도 keep 상태 저장
			}
			

			if (!turn.isEmpty()) {	// 비어있으면 뺄 주사위도 없음.

				dices[0].gotoxy(0, STARTPOINT2);
				dices[0].ClearScrollback();
				Sleep(700);

				cin.ignore();
				//cout << "저장된 주사위: "; turn.printAllKeepedDice(); cout << endl;		//이 라인 삭제하고 주사위 ui에 표시함!
				cout << "저장된 주사위에서 빼겠습니까? (y/n): "; cin >> choice;
				if (choice == 'y') {
					cin.ignore();
					cout << "저장된 주사위에서 뺄 주사위를 선택해주세요: ";
					//cin.ignore();
					int index_delete[5] = { 0, }; int i = 0;	// 저장된 주사위 중 뺄 주사위를 고름
					while (cin >> index_delete[i]) {			//뺄 주사위 입력받음
						i++;
						if (cin.peek() == '\n') { // Check for Enter key
							if (validInput(index_delete)) {
								break;
							}
							else {
								cout << "다시 입력하세요." << endl;
								i = 0;
								fill(begin(index_delete), end(index_delete), 0);
								cin.clear();
								cin.ignore();
								cout << "저장된 주사위에서 뺄 주사위를 선택해주세요: ";
								continue;
							}
						}
					}

					dices[0].gotoxy(0, STARTPOINT2); //커서 이동
					dices[0].ClearScrollback();

					turn.deleteDice(index_delete);	// 삭제할 index를 넘겨줌
					deleteDiceVIew(index_delete);	
				}
			}
			
			dices[0].gotoxy(0, STARTPOINT2); //커서 이동
			dices[0].ClearScrollback();
			cout << "한 번 더 던지시겠습니까? (y/n): "; // 저장하고 주사위를 더 굴릴 것인지 결정
			cin.ignore();
			cin >> choice;

			if (choice == 'n') break;	// 더 안 굴리면 while문을 빠져나와 모든 주사위를 저장함
//			4. out
//			keep된 Dice들을 다 출력(displayKeepedDice) -> 뺄 Dice의 index를 넘겨서 turn.deleteDice(index)로 넘겨줘!
			


			curTurn++;
		}
		turn.storeAllDice();	// 모든 주사위 저장


		// 점수 어디다 저장할지 정하는 부분( ->여기에 필요없음!)


		
		turnEnd();
	}

	bool validInput(const int* arr) {
		bool outOfRange = false;
		bool duplicated = false;

		for (int i = 0; i < 5; i++) {
			if (arr[i] < 0 || arr[i] > 5) {
				outOfRange = true; // 값이 올바르게 입력되었는지
			}

			for (int j = 4; j > i; j--) {
				if (arr[i] == arr[j] && arr[i] != 0) {
					duplicated = true; // 중복된 값이 있는지
				}
			}
		}

		if(outOfRange) {
			cout << "올바르지 않은 주사위 값이 포함되어 있습니다. 1에서 5 사이의 값을 입력하세요." << endl;
			return false;
		}
		else if (duplicated) {
			cout << "중복된 주사위 값이 포함되어 있습니다. 다른 값을 입력하세요." << endl;
			return false;
		}

		return true;
	}

	void turnEnd() {

		dices[0].gotoxy(0, STARTPOINT2);	//커서이동, 아래 화면지움
		dices[0].ClearScrollback();

		Sleep(700);
		board[currentPlayer].updateScore(turn.getKeep().getScores());	// 점수를 업데이트 함	(여기서 점수 어디다 저장할지 입력받음)	
		turn.initialize();	// turn 객체 초기화해서 다음 player의 정보를 저장할 수 있도록 함
		currentPlayer = (currentPlayer + 1) % numberOfPlayer;	// 다음 사람을 가르키도록 함
	}

	void winner() {
		dices[0].gotoxy(0, 0);
		system("cls");

		displayBoard();

		dices[0].gotoxy(0, 3);
		int winner_index = 0;
		int winner_score = board[0].calTotalResult();

		if (board.size() == 1) {
			cout << "(Score: " << winner_score << ")" << endl;
			return;
		}
		for (int i = 0; i < board.size(); i++) {
			int score = board[i].calTotalResult();
			if (score> winner_score) {
				winner_index = i;
				winner_score = score;
			}
		}
		cout << "Winner is player " << winner_index+1 << endl<<"(Score: " << winner_score << ")" << endl;

		dices[0].gotoxy(0, 25);
	}

	void displayBoard() {			//콘솔창 커서 이동 범위 문제때문에 우측에 표시하기로..
		system("cls"); //화면 비움..
		int i,j;
		int y = 0;	//커서 y축 위치

		dices[0].gotoxy(SCORESTART, y++);
		cout << "│ ";
		cout << "─────────────────<Score Board>─────────────────" << endl;

		dices[0].gotoxy(SCORESTART, y++);
		cout << "│ ";
		cout << "               ";
		for (i = 0; i < numberOfPlayer; i++) {
			if(i==currentPlayer)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);	//currentPlayer는 글자색 초록색으로 표시
			cout  << " Player" << i+1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	//글자색 다시 흰색으로 설정
		}
		//cout << endl;

		for (int i = 0; i < 6; i++) {
			dices[0].gotoxy(SCORESTART, y++);
			cout << "│ ";
			cout << " ";
			cout.width(16);
			cout << left << board[0].getScore(i).name;
			for (j = 0; j < numberOfPlayer; j++) {
				score boardScore = board[j].getScore(i);
				cout.width(8);
				if (boardScore.filled)				//점수가 채워진 상태면 점수 출력
					cout << board[j].getScore(i).score;
				else								//점수가 안채워졌으면 "-" 출력
					cout << "-";
			}
			//cout << endl;
		}

		//보너스 점수 출력
		dices[0].gotoxy(SCORESTART, y++);
		cout << "│ ";
		cout << " ";
		cout.width(16);
		cout << left<<"Bonus  ";
		for (j = 0; j < numberOfPlayer; j++) {
			cout.width(8);
			cout<<board[j].bonusScore();
			
		}
		//cout << endl;
		dices[0].gotoxy(SCORESTART, y++);
		cout << "│ ";
		cout << "-----------------------------------------------";// << endl;

		for (i = 6; i < 12 ; i++) {
			dices[0].gotoxy(SCORESTART, y++);
			cout << "│ ";
			cout << " ";
			cout.width(16);
			cout << left<<board[0].getScore(i).name;
			for (j = 0; j < numberOfPlayer; j++) {
				score boardScore = board[j].getScore(i);
				cout.width(8);
				if (boardScore.filled)				//점수가 채워진 상태면 점수 출력
					cout << board[j].getScore(i).score;
				else								//점수가 안채워졌으면 "-" 출력
					cout << "-";
			}
			//cout << endl;
		}

		//total점수 출력
		dices[0].gotoxy(SCORESTART, y++);
		cout << "│ ";
		cout << "-----------------------------------------------";// << endl;

		dices[0].gotoxy(SCORESTART, y++);
		cout << "│ ";
		cout << " ";
		cout.width(16);
		cout << left<<"Total  ";

		for (int j = 0; j < numberOfPlayer; j++) {
			cout.width(8);
			cout << board[j].calTotalResult();
		}

		//cout << endl;
		dices[0].gotoxy(SCORESTART, y++);
		cout << "│ ";
		cout << "───────────────────────────────────────────────"<<endl;

		dices[0].gotoxy(0, 0);

	}



	void initDiceView() {						//diceView 객체 위치, keep상태 초기화
		for (int i = 0; i < NUMOFDICE; i++) {
			dices[i].setPos(6 * i, DICEVIEWSTART);
			dices[i].keep(false);
		}
	}
	

	void drawDices() {			//diceView 객체를 콘솔화면에 그린다
		
		cout << "Press \"ENTER\" to Roll the Dice!" << endl;	//엔터 누르면 주사위 굴려짐

		//keep된 주사위 먼저 출력
		for (int i = 0; i < NUMOFDICE; i++) {
			dices[i].setNum(turn.getKeep().getDice(i)->getNumber());
			dices[i].drawDice(true);
		}

		int key;
		while (key = _getch() != 13) {}		//엔터 입력 이벤트 감지

		//keep 안된 주사위 새로 출력
		for (int i = 0; i < NUMOFDICE; i++) {
			dices[i].setNum(turn.getKeep().getDice(i)->getNumber());
			dices[i].drawDice(false);
			Sleep(1);
		}
		dices[0].gotoxy(0, DICEVIEWSTART+5);
	}

	void storeDiceView(const int* storeArr) {	//배열 받아서 keep상태 갱신
		int i = 0;
		int index = *storeArr;
		while (index!=0) {
			dices[index-1].keep(true);		//diceView.keep 함수 호출하면 주사위 모양 아래에 keep 표시 업데이트됨.
			i++;
			if (i >= 5)break;
			index = *(storeArr + i);
		}
		
	}
	void deleteDiceVIew(const int* deleteArr) {		//배열 받아서 keep상태 갱신
		int i = 0;
		int index = *deleteArr;
		while (index != 0) {
			dices[index-1].keep(false);
			i++;
			if (i >= 5)break;
			index = *(deleteArr + i);
		}
	}

	
	bool isGameOver() {				//모든 플레이어의 board가 모두 채워지면 true를 반환->게임 종료
		for (int i = 0; i < numberOfPlayer;i++) {
			if (board[i].isFilledAll() == false)
				return false;
		}
		return true;
	}
};
