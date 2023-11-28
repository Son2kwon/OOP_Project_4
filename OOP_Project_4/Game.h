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
	int currentPlayer;	// ���� �÷��̾ �������� ���� (0, 1, 2, ...)�� ǥ��

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
			
			/*
			1. ���� �ֻ����� turn���� ���� ��� �� ���
			2. ������ �ֻ����� index�� �Է� (1 ~ 5)
			3. ������ �ֻ����� keep�� ����
			*/

			turn.calScore();	// ���� ��� �� ���

			cout << "������ �ֻ����� �������ּ���: ";
			int index[5] = { 0, }; int i = 0;	// 0���� �ʱ�ȭ �صΰ�, 0�� �ƴ� �ֵ� index�� �����ϱ�
			while (cin >> index[i]) i++;

			turn.storeDice(index);	// index�� �Ѱ� turn�� �ִ� dice�� ����

			curTurn++;
		}
		
		
		turnEnd();
	}

	void turnEnd() {
		board[currentPlayer].updateScore();	// ������ ������Ʈ ��
		turn.initialize();	// turn ��ü �ʱ�ȭ�ؼ� ���� player�� ������ ������ �� �ֵ��� ��
		currentPlayer = (currentPlayer + 1) % numberOfPlayer;	// ���� ����� ����Ű���� ��
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

	}
};