#pragma once
#include<iostream>

class Keep {
private:
	vector<Dice> stored_Die; // Dice °´Ã¼ vector

public:
	Keep() {	// constructor

	}

	void storeNumber(int number) {

	}

	void deleteNumber() {

	}

	void calScore() {

	}

	void initialize() {
		stored_Die.clear();
	}

	Dice getDice(int index) {
		return stored_Die[index];
	}
};