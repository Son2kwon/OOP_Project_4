#pragma once
#include<iostream>
#include<string>
#include"Dice.h"
#include"scoreBoard.h"
#include"Turn.h"
using namespace std;

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
		turn.diceRoll();	// 주사위 굴림
		
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