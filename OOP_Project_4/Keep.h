#pragma once
#include<iostream>

class Keep {
private:
	vector<int> stored_Die;

public:
	Keep() {	// constructor

	}

	void storeNumber(Dice* dice) {	// �ϴ� ������ ���� ��
		for (int i = 0; i < 5; i++) {
			stored_Die.push_back(dice[i].getNumber());
		}
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
};