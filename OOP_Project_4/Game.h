#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include"Dice.h"
#include"scoreBoard.h"
#include"Turn.h"
using namespace std;

#define MAXTURN 3	// 한 턴 당 주사위는 3번 굴릴 수 있음

class Game {
private:
	int turn_left;
	vector<ScoreBoard> board;	// 한 사람의 점수판 모임 -> 총 점수판
	Turn turn;
	int numberOfPlayer;	// 총 플레이어 몇 명인지
	int currentPlayer;	// 지금 플레이어가 누구인지 순서 (0, 1, 2, ...)로 표현

public:
	Game() {	// constructor

	}

	void gameStart() {
		// board 초기화
		cout << "몇명이 플레이 하시겠습니까?: ";
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
		displayBoard();	// turn이 시작할 때 점수판을 보여줌

		int curTurn = 0;	// 총 3번의 기회 중 현재 몇 번 째인가?

		while (curTurn < MAXTURN) {	// 총 3번 굴리는 중
			turn.diceRoll();	// 주사위 굴림
			turn.displayDice();	// 굴린 주사위의 결과 출력
			
//			1. 나온 주사위를 turn에서 점수 계산 및 출력
//			2. 저장할 주사위의 index를 입력 (1 ~ 5)
//			3. 저장할 주사위를 keep에 저장

			turn.calScore();	// 점수 계산 및 출력

			if (curTurn == MAXTURN - 1) break;	// 사실 마지막 기회라면 던지고 끝

			cout << "한 번 더 던지시겠습니까? "; char choice;	// 점수를 출력하고 주사위를 더 굴릴 것인지 결정
			cin >> choice;

			if (choice == 'n') break;	// 더 안 굴리면 while문을 빠져나와 모든 주사위를 저장함


			cout << "저장할 주사위를 선택해주세요: ";
			int index_store[5] = { 0, }; int i = 0;	// 0으로 초기화 해두고, 0이 아닌 애들 index만 저장하기
			while (cin >> index_store[i]) i++;

			turn.storeDice(index_store);	// index를 넘겨 turn에 있는 dice를 저장

			cout << "저장된 주사위에서 뺄 주사위를 선택해주세요: ";	
			int index_delete[5] = { 0, }; i = 0;	// 저장된 주사위 중 뺄 주사위를 고름
			while (cin >> index_delete[i]) i++;
			turn.deleteDice(index_delete);	// 삭제할 index를 넘겨줌
			
//			4. out
//			keep된 Dice들을 다 출력(displayKeepedDice) -> 뺄 Dice의 index를 넘겨서 turn.deleteDice(index)로 넘겨줘!
			
			

			curTurn++;
		}
		turn.storeAllDice();	// 모든 주사위 저장

		// 점수 어디다 저장할지 정하는 부분


		
		turnEnd();
	}

	void turnEnd() {
		board[currentPlayer].updateScore();	// 점수를 업데이트 함
		turn.initialize();	// turn 객체 초기화해서 다음 player의 정보를 저장할 수 있도록 함
		currentPlayer = (currentPlayer + 1) % numberOfPlayer;	// 다음 사람을 가르키도록 함
	}

	void winner() {
		int winner_index = 0;
		int winner_score = board[0].calTotalResult();
		for (int i = 0; i < board.size(); i++) {
			int score = board[i].calTotalResult();
			if (score> winner_score) {
				winner_index = i;
				winner_score = score;
			}
		}
		cout << "Winner is player " << winner_index << ", (Score: " << winner_score << ")" << endl;
	}

	void displayBoard() {
		system("cls"); //화면 비움..
		int i,j;

		cout << "              ";
		for (i = 0; i < numberOfPlayer; i++) {
			cout  << " Player" << i;
		}
		cout << endl;

		for (i = 0; i < 12 ; i++) {
			cout.width(15);
			cout << left<<board[0].getScore(i).name;
			for (j = 0; j < numberOfPlayer; j++) {
				score boardScore = board[j].getScore(i);
				cout.width(8);
				if (boardScore.filled)				//점수가 채워진 상태면 점수 출력
					cout << board[j].getScore(i).score;
				else								//점수가 안채워졌으면 "-" 출력
					cout << "-";
			}
			cout << endl;
		}

	}
	bool isGameOver() {				//모든 플레이어의 board가 모두 채워지면 true를 반환->게임 종료
		for (int i = 0; i < numberOfPlayer;i++) {
			if (board[i].isFilledAll() == false)
				return false;
		}
	}
};