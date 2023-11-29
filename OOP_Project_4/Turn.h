#pragma once
#include<iostream>
#include"Dice.h"
#include"Keep.h"
using namespace std;

#define NUMOFDICE	5

class Turn {
private:
	Keep keep;

public:
	/*
	diceRoll -> keep/out ���� -> saveKeepedDice

	diceRoll -> �ֻ����� keeped ���°� �ƴ϶�� ������

	keep ���� -> keep ��ü�� Dice ��ü ������ keeped ���� true�� ����
	out ���� -> keep ��ü�� Dice ��ü ������ keeped ���� false�� ����

	*/
	Turn() {	// constructor

	}

	void diceRoll() { // �ֻ����� keep ���� �ʾ����� ������
		/*for (int i = 0; i < NUMOFDICE; i++) {
			if (!keep.getDice(i).getKeeped()) {
				keep.getDice(i).roll();
			}
		}*/

		keep.roll();
	}

	void initialize() {
		keep.initialize();
	}

	void displayDice() {	// �ֻ����� ���� ȭ�鿡 ǥ���ϴ� �Լ�
		for (int i = 0; i < 5; i++) {
			Dice* dice = keep.getDice(i);
			cout << dice->getNumber() << " ";
		}

		cout << endl;
	}

	void displayKeepedDice() {
		for (int i = 0; i < 5; i++) {
			Dice* dice = keep.getDice(i);
			if (dice->getKeeped()) {
				cout << dice->getNumber() << " ";
			}
			else {
				cout << "_ ";
			}
		}
		
		cout << endl;
	}

	void calScore() {
		keep.calScore();
	}

	void storeDice(const int* index) {
		int i = 0;
		while (*(index + i) != 0 && i < NUMOFDICE) {
			Dice* dice = keep.getDice(*(index + i) - 1);
			keep.storeNumber(dice);
			i++;
		}
	}

	void deleteDice(const int* index) {
		int i = 0;
		while (*(index + i) != 0) {
			Dice* dice = keep.getDice(i);
			keep.deleteNumber(dice);	// �Է¹��� index�� ���� ����
			i++;
		}
	}

	void storeAllDice() {
		for (int i = 0; i < NUMOFDICE; i++) {
			Dice* dice = keep.getDice(i);
			keep.storeNumber(dice);
		}
	}

	void printAllKeepedDice() {	// ����� ��� �ֻ����� ���� ����ϴ� �Լ�
		for (int i = 0; i < NUMOFDICE; i++) {
			Dice* dice = keep.getDice(i);
			if (dice->getKeeped()) cout << dice->getNumber() << " ";
		}
	}

	bool isEmpty() {
		return keep.isEmpty();
	}
};