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
	diceRoll -> keep/out 결정 -> saveKeepedDice

	diceRoll -> 주사위가 keeped 상태가 아니라면 굴리기

	keep 결정 -> keep 객체의 Dice 객체 벡터의 keeped 값을 true로 변경
	out 결정 -> keep 객체의 Dice 객체 벡터의 keeped 값을 false로 변경

	*/
	Turn() {	// constructor

	}

	void diceRoll() { // 주사위가 keep 되지 않았으면 굴리기
		for (int i = 0; i < 5; i++) {
			if (!keep.getDice(i).getKeeped()) {
				keep.getDice(i).roll();
			}
		}
	}
	

	void initialize() {
		keep.initialize();
	}

	void displayDice() {	// 주사위의 눈을 화면에 표시하는 함수
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
		// keep에 있는 calScore 그대로 복사 붙여넣기 하기. 
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