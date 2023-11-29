#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
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
		cout << "����� �÷��� �Ͻðڽ��ϱ�?: ";
		cin >> numberOfPlayer;

		//�ο����� ���� board ���� �ʱ�ȭ
		for (int i = 0; i < numberOfPlayer; i++) {		
			board.push_back(ScoreBoard());
		}	
		//��� ������ ä���������� turnStart ȣ��
		while (!isGameOver()) {
			turnStart();
		}
		winner();
	}

	void turnStart() {
		displayBoard();	// turn�� ������ �� �������� ������

		int curTurn = 0;	// �� 3���� ��ȸ �� ���� �� �� °�ΰ�?

		while (curTurn < MAXTURN) {	// �� 3�� ������ ��
			turn.diceRoll();	// �ֻ��� ����
			turn.displayDice();	// ���� �ֻ����� ��� ���
			
//			1. ���� �ֻ����� turn���� ���� ��� �� ���
//			2. ������ �ֻ����� index�� �Է� (1 ~ 5)
//			3. ������ �ֻ����� keep�� ����

			turn.calScore();	// ���� ��� �� ���

			if (curTurn == MAXTURN - 1) break;	// ��� ������ ��ȸ��� ������ ��

			cout << "�� �� �� �����ðڽ��ϱ�? "; char choice;	// ������ ����ϰ� �ֻ����� �� ���� ������ ����
			cin >> choice;

			if (choice == 'n') break;	// �� �� ������ while���� �������� ��� �ֻ����� ������


			cout << "������ �ֻ����� �������ּ���: ";
			int index_store[5] = { 0, }; int i = 0;	// 0���� �ʱ�ȭ �صΰ�, 0�� �ƴ� �ֵ� index�� �����ϱ�
			while (cin >> index_store[i]) i++;

			turn.storeDice(index_store);	// index�� �Ѱ� turn�� �ִ� dice�� ����

			cout << "����� �ֻ������� �� �ֻ����� �������ּ���: ";	
			int index_delete[5] = { 0, }; i = 0;	// ����� �ֻ��� �� �� �ֻ����� ��
			while (cin >> index_delete[i]) i++;
			turn.deleteDice(index_delete);	// ������ index�� �Ѱ���
			
//			4. out
//			keep�� Dice���� �� ���(displayKeepedDice) -> �� Dice�� index�� �Ѱܼ� turn.deleteDice(index)�� �Ѱ���!
			
			

			curTurn++;
		}
		turn.storeAllDice();	// ��� �ֻ��� ����

		// ���� ���� �������� ���ϴ� �κ�


		
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
		system("cls"); //ȭ�� ���..
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
				if (boardScore.filled)				//������ ä���� ���¸� ���� ���
					cout << board[j].getScore(i).score;
				else								//������ ��ä�������� "-" ���
					cout << "-";
			}
			cout << endl;
		}

	}
	bool isGameOver() {				//��� �÷��̾��� board�� ��� ä������ true�� ��ȯ->���� ����
		for (int i = 0; i < numberOfPlayer;i++) {
			if (board[i].isFilledAll() == false)
				return false;
		}
	}
};