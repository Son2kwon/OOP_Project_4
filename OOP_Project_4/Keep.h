#pragma once
#include<iostream>

class Keep {
private:
	vector<Dice> stored_Die; // Dice ��ü vector

public:
	Keep() {	// constructor

	}

	void storeNumber(Dice dice) {
		stored_Die.push_back(dice);
	}

	void deleteNumber(int* index) {
		int i = 0;
		int index[5] = { 1,2,3,4,5 };
		while (index[i] != 0) {
			// index�� ���� ���� �� ��
			
		}
	}

	void calScore() {
		// ���� ���
	}

	void initialize() {
		stored_Die.clear();
	}

	Dice getDice(int index) {
		return stored_Die[index];
	}
};