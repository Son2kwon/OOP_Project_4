#pragma once
#include<iostream>
#include"Dice.h"
#include"Keep.h"
using namespace std;

class Turn {
private:
	Dice dice[5];
	Keep keep;

public:
	Turn() {	// constructor

	}

	void diceRoll() {
		for(int i = 0; i < 5; i++)
			dice[i].roll();
	}

	void initialize() {
		for (int i = 0; i < 5; i++) dice[i].initialize();
		keep.initialize();
	}

	void displayDice() {	// 주사위의 눈을 화면에 표시하는 함수
		for (int i = 0; i < 5; i++)
			cout << dice[i].getNumber() << " ";

		cout << endl;
	}

	void calScore() {
		// keep에 있는 calScore 그대로 복사 붙여넣기 하기. 
	}

	void storeDice(int* index) {
		int i = 0;
		while (*(index + i) != 0) {
			keep.storeNumber(dice[i]);
			i++;
		}
	}

	void deleteNumber(int* index) {
		
	}
};