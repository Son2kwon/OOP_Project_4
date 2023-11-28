#pragma once
#include<iostream>
#include"Dice.h"
#include"Keep.h"
using namespace std;

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
		// keep�� �ִ� calScore �״�� ���� �ٿ��ֱ� �ϱ�. 
	}

	void storeDice(int* index) {
		int i = 0;
		while (*(index + i) != 0) {
			keep.storeNumber(keep.getDice(i-1));
			i++;
		}
	}

	void deleteDice(int* index) {
		
	}
};