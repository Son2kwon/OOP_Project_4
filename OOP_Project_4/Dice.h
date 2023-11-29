#pragma once
#include<iostream>
#include<random>

class Dice {
private:
	int number;	// �ֻ����� ��
	bool keeped = false; // �ֻ����� keep �Ǿ����� �ƴ���

public:
	Dice() {	// constructor
		number = 0;
	}


	void roll() {	// �ֻ����� ����
		srand(time(NULL));	// ������ ���� seed ����

		number = (rand() % 6) + 1;	// number�� 1 ~ 6 �� �ϳ��� random�ϰ� ����
	}

	void initialize() {
		number = 0;
	}

	int getNumber() const {
		return number;
	}

	void setKeeped() {	// ���� �Ű����� ���� �׳� true�� �����ϸ� �� �� ����
		this->keeped = true;
	}

	void setOut() {
		this->keeped = false;
	}

	bool getKeeped() {
		return this->keeped;
	}
};