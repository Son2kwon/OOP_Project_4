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
			
			/*
			1. ���� �ֻ����� ����� ��� keep�� ����
			2. ���� ��� �� ���
			3. ������ �ֻ����� index�� �Է� (1 ~ 5)
			4. ������ �ֻ��� ���� �������� vector���� ����
			*/
			turn.storeDice();	// ���� �ֻ����� ����� ��� keep�� ����
			turn.calScore();	// ���� ��� �� ���

			cout << "������ �ֻ����� �������ּ���: ";
			int index[5] = { 0, }; int i = 0;
			while (cin >> index[i]) i++;

			turn.deleteNumber(index);
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