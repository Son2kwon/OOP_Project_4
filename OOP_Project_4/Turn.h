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
};