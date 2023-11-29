#pragma once
#include<iostream>
#include<random>

class Dice {
private:
	int number;	// 주사위의 눈
	bool keeped = false; // 주사위가 keep 되었는지 아닌지

public:
	Dice() {	// constructor
		number = 0;
	}


	void roll() {	// 주사위를 굴림
		srand(time(NULL));	// 난수를 위한 seed 설정

		number = (rand() % 6) + 1;	// number에 1 ~ 6 중 하나를 random하게 저장
	}

	void initialize() {
		number = 0;
	}

	int getNumber() const {
		return number;
	}

	void setKeeped() {	// 굳이 매개변수 없이 그냥 true로 설정하면 될 것 같아
		this->keeped = true;
	}

	void setOut() {
		this->keeped = false;
	}

	bool getKeeped() {
		return this->keeped;
	}
};