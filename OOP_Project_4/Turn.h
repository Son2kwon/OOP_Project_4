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
		for (int i = 0; i < 5; i++) {
			if (!keep.getDice(i).getKeeped()) {
				keep.getDice(i).roll();
			}
		}
	}
	

	void initialize() {
		keep.initialize();
	}

	void displayDice() {	// �ֻ����� ���� ȭ�鿡 ǥ���ϴ� �Լ�
		for (int i = 0; i < 5; i++)
			cout << keep.getDice(i).getNumber() << " ";

		cout << endl;
	}

	void displayKeepedDice() {
		for (int i = 0; i < 5; i++) {
			if (keep.getDice(i).getKeeped()) {
				cout << keep.getDice(i).getNumber() << " ";
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

	void storeDice(int* index) {
		int i = 0;
		while (*(index + i) != 0) {
			keep.storeNumber(keep.getDice(i));	// i�� �׳� �ε����� i-1���� i�� �ٲ�
			i++;
		}
	}

	void deleteDice(int* index) {
		int i = 0;
		while (*(index + i) != 0) {
			keep.deleteNumber(keep.getDice(i));	// �Է¹��� index�� ���� ����
			i++;
		}
	}

	void storeAllDice() {
		for (int i = 0; i < NUMOFDICE; i++) {
			keep.storeNumber(keep.getDice(i));
		}
	}
};