#pragma once
#include<iostream>

class Keep {
private:
	vector<Dice> stored_Die; // Dice 객체 vector

public:
	Keep() : stored_Die(5, Dice()) {	// constructor

	}

	void storeNumber(Dice dice) {
		dice.setKeeped(true);
	}

	void deleteNumber(int* index) {
		int i = 0;
		int index[5] = { 1,2,3,4,5 };
		while (index[i] != 0) {
			// index에 없는 값을 뺄 것
			
		}
	}

	void calScore() {
		// 점수 계산
	}

	void initialize() {
		stored_Die.clear();
	}

	Dice getDice(int index) {
		return stored_Die[index];
	}
};