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
			// 주사위를 저장함
			// 점수를 선택했다면 break
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