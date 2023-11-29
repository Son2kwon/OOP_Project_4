#pragma once
#include<iostream>
#include<chrono>
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
		//srand(time(NULL));	// ������ ���� seed ����

		//this->number = (rand() % 6) + 1;	// number�� 1 ~ 6 �� �ϳ��� random�ϰ� ����

		// Use the current time as a seed
		unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());

		// Initialize a random number generator with the seed
		std::default_random_engine generator(seed);

		// Create a distribution for the range of numbers you want
		std::uniform_int_distribution<int> distribution(1, 6);

		// Generate a random number
		int randomNumber = distribution(generator);

		this->number = randomNumber;
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