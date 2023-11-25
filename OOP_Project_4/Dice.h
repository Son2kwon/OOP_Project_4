#pragma once
#include<iostream>
#include<random>

class Dice {
private:
	int number;	// 주사위의 눈

public:
	Dice() {	// constructor
		number = 0;
	}

	void roll() {	// 주사위를 굴림
		srand(time(NULL));	// 난수를 위한 seed 설정

		switch (rand() % 6 + 1) {	// 숫자는 1 ~ 6
		case 1:
			number = 1;
			break;
		case 2:
			number = 2;
			break;
		case 3:
			number = 3;
			break;
		case 4:
			number = 4;
			break;
		case 5:
			number = 5;
			break;
		case 6:
			number = 6;
			break;
		}
	}

	void initialize() {
		number = 0;
	}
};