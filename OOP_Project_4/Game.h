#pragma once
#include<iostream>
#include<string>
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
	int currentPlayer;	// 지금 플레이어가 누구인지

public:
	Game() {	// constructor

	}

	void gameStart() {
		// board 초기화
	}

	void turnStart() {
		displayBoard();	// turn이 시작할 때 점수판을 보여줌

		int curTurn = 0;	// 총 3번의 기회 중 현재 몇 번 째인가?

		while (curTurn < MAXTURN) {	// 총 3번 굴리는 중
			turn.diceRoll();	// 주사위 굴림
			turn.displayDice();	// 굴린 주사위의 결과 출력
			
			/*
			1. 나온 주사위의 결과를 모두 keep에 저장
			2. 점수 계산 및 출력
			3. 저장할 주사위의 index를 입력 (1 ~ 5)
			4. 저장할 주사위 빼고 나머지는 vector에서 삭제
			*/
			turn.storeDice();	// 나온 주사위의 결과를 모두 keep에 저장
			turn.calScore();	// 점수 계산 및 출력

			cout << "저장할 주사위를 선택해주세요: ";
			int index[5] = { 0, }; int i = 0;
			while (cin >> index[i]) i++;

			turn.deleteNumber(index);
		}
		
		
		turnEnd();
	}

	void turnEnd() {
		board[currentPlayer].updateScore();	// 점수를 업데이트 함
		turn.initialize();	// turn 객체 초기화해서 다음 player의 정보를 저장할 수 있도록 함
		currentPlayer = (currentPlayer + 1) % numberOfPlayer;	// 다음 사람을 가르키도록 함
	}

	void winner() {

	}

	void displayBoard() {

	}
};