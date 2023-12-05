#pragma once
#include<iostream>
#include<chrono>
#include<random>

class Dice {
private:
	int number;	// 주사위의 눈
	bool keeped = false; // 주사위가 keep 되었는지 아닌지

public:
	Dice() {	// constructor
		number = 0;
		keeped = false;
	}


	void roll() {	// 주사위를 굴림
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