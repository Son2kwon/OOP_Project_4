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
		turn.diceRoll();	// �ֻ��� ����
		
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