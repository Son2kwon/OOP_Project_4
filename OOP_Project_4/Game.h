#pragma once
#include<iostream>
#include<string>
#include"Dice.h"
#include"scoreBoard.h"
#include"Turn.h"
using namespace std;

#define MAXTURN 3	// �� �� �� �ֻ����� 3�� ���� �� ����

class Game {
private:
	int turn_left;
	vector<ScoreBoard> board;	// �� ����� ������ ���� -> �� ������
	Turn turn;
	int numberOfPlayer;	// �� �÷��̾� �� ������
	int currentPlayer;	// ���� �÷��̾ ��������

public:
	Game() {	// constructor

	}

	void gameStart() {
		// board �ʱ�ȭ
	}

	void turnStart() {
		displayBoard();	// turn�� ������ �� �������� ������

		int curTurn = 0;	// �� 3���� ��ȸ �� ���� �� �� °�ΰ�?

		while (curTurn < MAXTURN) {	// �� 3�� ������ ��
			turn.diceRoll();	// �ֻ��� ����
			turn.displayDice();	// ���� �ֻ����� ��� ���
			// �ֻ����� ������
			// ������ �����ߴٸ� break
		}
		
		
		turnEnd();
	}

	void turnEnd() {
		board[currentPlayer].updateScore();	// ������ ������Ʈ ��
		turn.initialize();	// turn ��ü �ʱ�ȭ�ؼ� ���� player�� ������ ������ �� �ֵ��� ��
		currentPlayer = (currentPlayer + 1) % numberOfPlayer;	// ���� ����� ����Ű���� ��
	}

	void winner() {

	}

	void displayBoard() {

	}
};