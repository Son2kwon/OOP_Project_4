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
	diceRoll -> keep/out 결정 -> saveKeepedDice

	diceRoll -> 주사위가 keeped 상태가 아니라면 굴리기

	keep 결정 -> keep 객체의 Dice 객체 벡터의 keeped 값을 true로 변경
	out 결정 -> keep 객체의 Dice 객체 벡터의 keeped 값을 false로 변경

	*/
	Turn() {	// constructor

	}

	void diceRoll() { // 주사위가 keep 되지 않았으면 굴리기
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

	void displayDice() {	// 주사위의 눈을 화면에 표시하는 함수
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
			keep.deleteNumber(dice);	// 입력받은 index에 따라 삭제
			i++;
		}
	}

	void storeAllDice() {
		for (int i = 0; i < NUMOFDICE; i++) {
			Dice* dice = keep.getDice(i);
			keep.storeNumber(dice);
		}
	}

	Keep getKeep() {
		return keep;


	void printAllKeepedDice() {	// 저장된 모든 주사위의 눈을 출력하는 함수
		for (int i = 0; i < NUMOFDICE; i++) {
			Dice* dice = keep.getDice(i);
			if (dice->getKeeped()) cout << dice->getNumber() << " ";
		}
	}

	bool isEmpty() {
		return keep.isEmpty();

	}
};