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

#define MAXTURN 3	// �� �� �� �ֻ����� 3�� ���� �� ����
#define NUMOFDICE 5

#define DICEVIEWSTART 3	//Ŀ�� �̵���ġ �����..
#define STARTPOINT2 21
#define SCORESTART 50

class Game {
private:
	int turn_left;
	vector<ScoreBoard> board;	// �� ����� ������ ���� -> �� ������
	Turn turn;
	int numberOfPlayer;	// �� �÷��̾� �� ������
	int currentPlayer;	// ���� �÷��̾ �������� ���� (0, 1, 2, ...)�� ǥ��
	diceView dices[NUMOFDICE];	//diceView�� �ܼ�â�� �ֻ��� ����� ���� Ŭ����.

public:
	Game() {	// constructor

	}

	void gameStart() {

		int key;
		cout << "  << Yacht Game >>" << endl << endl;
		cout << "Press Enter to start!!";		//enter ������ ����

		while(key=_getch()!=13){}	//enter Ű �Է� ����


		// board �ʱ�ȭ
		cout << endl<<endl<<"����� �÷��� �Ͻðڽ��ϱ�?: ";
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

		initDiceView();		//diceView�� �ʱ�ȭ(��ġ, keep����)

		int curTurn = 0;	// �� 3���� ��ȸ �� ���� �� �� °�ΰ�?

		while (curTurn < MAXTURN) {	// �� 3�� ������ ��
			displayBoard();		//�ֻ��� ���������� �����ǵ� ��µǴ°ɷ�..
			turn.diceRoll();	// �ֻ��� ����
			Sleep(500);

			cout << "[Player " << currentPlayer + 1 << "]" << endl<<endl;
			Sleep(1000);
			
			drawDices();
			

//			1. ���� �ֻ����� turn���� ���� ��� �� ���
//			2. ������ �ֻ����� index�� �Է� (1 ~ 5)
//			3. ������ �ֻ����� keep�� ����

			Sleep(600);
			turn.calScore();	// ���� ��� �� ���
			cout << endl;
			Sleep(600);

			if (curTurn == MAXTURN - 1) break;	// ��� ������ ��ȸ��� ������ ��

			cin.ignore();
			cout << "�ֻ����� �����Ͻðڽ��ϱ�? (y/n): "; char choice; cin >> choice;

			if (choice == 'y') {
				cout << "������ �ֻ����� �������ּ���: ";
				int index_store[5] = { 0, }; int i = 0;	// 0���� �ʱ�ȭ �صΰ�, 0�� �ƴ� �ֵ� index�� �����ϱ�
				cin.ignore();
				while (cin >> index_store[i]) {
					i++;
					if (cin.peek() == '\n') { // Check for Enter key
						if (validInput(index_store)) { // �Է��� ��ȿ���� �Ǵ��ϴ� �Լ�
							break;
						}
						else {
							cout << "�ٽ� �Է��ϼ���." << endl;
							i = 0;
							fill(begin(index_store), end(index_store), 0);
							cin.clear();
							cin.ignore();
							cout << "������ �ֻ����� �������ּ���: ";
							continue;
						}
					}
				}

				turn.storeDice(index_store);	// index�� �Ѱ� turn�� �ִ� dice�� ����
				storeDiceView(index_store);		//diceView��ü���� keep ���� ����
			}
			

			if (!turn.isEmpty()) {	// ��������� �� �ֻ����� ����.

				dices[0].gotoxy(0, STARTPOINT2);
				dices[0].ClearScrollback();
				Sleep(700);

				cin.ignore();
				//cout << "����� �ֻ���: "; turn.printAllKeepedDice(); cout << endl;		//�� ���� �����ϰ� �ֻ��� ui�� ǥ����!
				cout << "����� �ֻ������� ���ڽ��ϱ�? (y/n): "; cin >> choice;
				if (choice == 'y') {
					cin.ignore();
					cout << "����� �ֻ������� �� �ֻ����� �������ּ���: ";
					//cin.ignore();
					int index_delete[5] = { 0, }; int i = 0;	// ����� �ֻ��� �� �� �ֻ����� ��
					while (cin >> index_delete[i]) {			//�� �ֻ��� �Է¹���
						i++;
						if (cin.peek() == '\n') { // Check for Enter key
							if (validInput(index_delete)) {
								break;
							}
							else {
								cout << "�ٽ� �Է��ϼ���." << endl;
								i = 0;
								fill(begin(index_delete), end(index_delete), 0);
								cin.clear();
								cin.ignore();
								cout << "����� �ֻ������� �� �ֻ����� �������ּ���: ";
								continue;
							}
						}
					}

					dices[0].gotoxy(0, STARTPOINT2); //Ŀ�� �̵�
					dices[0].ClearScrollback();

					turn.deleteDice(index_delete);	// ������ index�� �Ѱ���
					deleteDiceVIew(index_delete);	
				}
			}
			
			dices[0].gotoxy(0, STARTPOINT2); //Ŀ�� �̵�
			dices[0].ClearScrollback();
			cout << "�� �� �� �����ðڽ��ϱ�? (y/n): "; // �����ϰ� �ֻ����� �� ���� ������ ����
			cin.ignore();
			cin >> choice;

			if (choice == 'n') break;	// �� �� ������ while���� �������� ��� �ֻ����� ������
//			4. out
//			keep�� Dice���� �� ���(displayKeepedDice) -> �� Dice�� index�� �Ѱܼ� turn.deleteDice(index)�� �Ѱ���!
			


			curTurn++;
		}
		turn.storeAllDice();	// ��� �ֻ��� ����


		// ���� ���� �������� ���ϴ� �κ�( ->���⿡ �ʿ����!)


		
		turnEnd();
	}

	bool validInput(const int* arr) {
		bool outOfRange = false;
		bool duplicated = false;

		for (int i = 0; i < 5; i++) {
			if (arr[i] < 0 || arr[i] > 5) {
				outOfRange = true; // ���� �ùٸ��� �ԷµǾ�����
			}

			for (int j = 4; j > i; j--) {
				if (arr[i] == arr[j] && arr[i] != 0) {
					duplicated = true; // �ߺ��� ���� �ִ���
				}
			}
		}

		if(outOfRange) {
			cout << "�ùٸ��� ���� �ֻ��� ���� ���ԵǾ� �ֽ��ϴ�. 1���� 5 ������ ���� �Է��ϼ���." << endl;
			return false;
		}
		else if (duplicated) {
			cout << "�ߺ��� �ֻ��� ���� ���ԵǾ� �ֽ��ϴ�. �ٸ� ���� �Է��ϼ���." << endl;
			return false;
		}

		return true;
	}

	void turnEnd() {

		dices[0].gotoxy(0, STARTPOINT2);	//Ŀ���̵�, �Ʒ� ȭ������
		dices[0].ClearScrollback();

		Sleep(700);
		board[currentPlayer].updateScore(turn.getKeep().getScores());	// ������ ������Ʈ ��	(���⼭ ���� ���� �������� �Է¹���)	
		turn.initialize();	// turn ��ü �ʱ�ȭ�ؼ� ���� player�� ������ ������ �� �ֵ��� ��
		currentPlayer = (currentPlayer + 1) % numberOfPlayer;	// ���� ����� ����Ű���� ��
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

	void displayBoard() {			//�ܼ�â Ŀ�� �̵� ���� ���������� ������ ǥ���ϱ��..
		system("cls"); //ȭ�� ���..
		int i,j;
		int y = 0;	//Ŀ�� y�� ��ġ

		dices[0].gotoxy(SCORESTART, y++);
		cout << "�� ";
		cout << "����������������������������������<Score Board>����������������������������������" << endl;

		dices[0].gotoxy(SCORESTART, y++);
		cout << "�� ";
		cout << "               ";
		for (i = 0; i < numberOfPlayer; i++) {
			if(i==currentPlayer)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);	//currentPlayer�� ���ڻ� �ʷϻ����� ǥ��
			cout  << " Player" << i+1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	//���ڻ� �ٽ� ������� ����
		}
		//cout << endl;

		for (int i = 0; i < 6; i++) {
			dices[0].gotoxy(SCORESTART, y++);
			cout << "�� ";
			cout << " ";
			cout.width(16);
			cout << left << board[0].getScore(i).name;
			for (j = 0; j < numberOfPlayer; j++) {
				score boardScore = board[j].getScore(i);
				cout.width(8);
				if (boardScore.filled)				//������ ä���� ���¸� ���� ���
					cout << board[j].getScore(i).score;
				else								//������ ��ä�������� "-" ���
					cout << "-";
			}
			//cout << endl;
		}

		//���ʽ� ���� ���
		dices[0].gotoxy(SCORESTART, y++);
		cout << "�� ";
		cout << " ";
		cout.width(16);
		cout << left<<"Bonus  ";
		for (j = 0; j < numberOfPlayer; j++) {
			cout.width(8);
			cout<<board[j].bonusScore();
			
		}
		//cout << endl;
		dices[0].gotoxy(SCORESTART, y++);
		cout << "�� ";
		cout << "-----------------------------------------------";// << endl;

		for (i = 6; i < 12 ; i++) {
			dices[0].gotoxy(SCORESTART, y++);
			cout << "�� ";
			cout << " ";
			cout.width(16);
			cout << left<<board[0].getScore(i).name;
			for (j = 0; j < numberOfPlayer; j++) {
				score boardScore = board[j].getScore(i);
				cout.width(8);
				if (boardScore.filled)				//������ ä���� ���¸� ���� ���
					cout << board[j].getScore(i).score;
				else								//������ ��ä�������� "-" ���
					cout << "-";
			}
			//cout << endl;
		}

		//total���� ���
		dices[0].gotoxy(SCORESTART, y++);
		cout << "�� ";
		cout << "-----------------------------------------------";// << endl;

		dices[0].gotoxy(SCORESTART, y++);
		cout << "�� ";
		cout << " ";
		cout.width(16);
		cout << left<<"Total  ";

		for (int j = 0; j < numberOfPlayer; j++) {
			cout.width(8);
			cout << board[j].calTotalResult();
		}

		//cout << endl;
		dices[0].gotoxy(SCORESTART, y++);
		cout << "�� ";
		cout << "����������������������������������������������������������������������������������������������"<<endl;

		dices[0].gotoxy(0, 0);

	}



	void initDiceView() {						//diceView ��ü ��ġ, keep���� �ʱ�ȭ
		for (int i = 0; i < NUMOFDICE; i++) {
			dices[i].setPos(6 * i, DICEVIEWSTART);
			dices[i].keep(false);
		}
	}
	

	void drawDices() {			//diceView ��ü�� �ܼ�ȭ�鿡 �׸���
		
		cout << "Press \"ENTER\" to Roll the Dice!" << endl;	//���� ������ �ֻ��� ������

		//keep�� �ֻ��� ���� ���
		for (int i = 0; i < NUMOFDICE; i++) {
			dices[i].setNum(turn.getKeep().getDice(i)->getNumber());
			dices[i].drawDice(true);
		}

		int key;
		while (key = _getch() != 13) {}		//���� �Է� �̺�Ʈ ����

		//keep �ȵ� �ֻ��� ���� ���
		for (int i = 0; i < NUMOFDICE; i++) {
			dices[i].setNum(turn.getKeep().getDice(i)->getNumber());
			dices[i].drawDice(false);
			Sleep(1);
		}
		dices[0].gotoxy(0, DICEVIEWSTART+5);
	}

	void storeDiceView(const int* storeArr) {	//�迭 �޾Ƽ� keep���� ����
		int i = 0;
		int index = *storeArr;
		while (index!=0) {
			dices[index-1].keep(true);		//diceView.keep �Լ� ȣ���ϸ� �ֻ��� ��� �Ʒ��� keep ǥ�� ������Ʈ��.
			i++;
			if (i >= 5)break;
			index = *(storeArr + i);
		}
		
	}
	void deleteDiceVIew(const int* deleteArr) {		//�迭 �޾Ƽ� keep���� ����
		int i = 0;
		int index = *deleteArr;
		while (index != 0) {
			dices[index-1].keep(false);
			i++;
			if (i >= 5)break;
			index = *(deleteArr + i);
		}
	}

	
	bool isGameOver() {				//��� �÷��̾��� board�� ��� ä������ true�� ��ȯ->���� ����
		for (int i = 0; i < numberOfPlayer;i++) {
			if (board[i].isFilledAll() == false)
				return false;
		}
		return true;
	}
};
