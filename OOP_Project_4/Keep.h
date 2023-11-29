#pragma once
#include<iostream>

#define NUMOFDICE 5

class Keep {
private:
	vector<Dice> stored_Die; // Dice 객체 vector
	int scores[13]; /*
	[0-5]		Ones, Twos, Threes, Fours, Fives, Sixes
	[6]			Choice
	[7]			Four of a Kind
	[8]			Full House
	[9]			Little Striaght
	[10]		Big Straight
	[11]		Yacht
	[12]		Bouns
	*/

public:
	Keep() : stored_Die(5, Dice()) {	// constructor

	}

	void storeNumber(Dice dice) {
		dice.setKeeped();
	}

	void deleteNumber(Dice dice) {
		dice.setOut();	// keep을 false로 넘김
	}

	void calScore() {
		// 점수 계산
		int ones = 0;
		int twos = 0;
		int threes = 0;
		int fours = 0;
		int fives = 0;
		int sixes = 0;

		int choice = 0;
		int foak = 0;
		int fh = 0;
		int ls = 0;
		int bs = 0;
		int yacht = 0;
		int bonus = 0;
		int count[6] = { 0, }; // Dice들이 나온 횟수

		// ONES, TWOS, THREES, FOURS, FIVES, SIXES, CHOICE
		for (const Dice& dice : stored_Die) {
			switch (dice.getNumber()) {
			case 1:
				ones++;
				choice += 1;
				count[0]++;
				break;
			case 2:
				twos += 2;
				choice += 2;
				count[1]++;
				break;
			case 3:
				threes += 3;
				choice += 3;
				count[2]++;
				break;
			case 4:
				fours += 4;
				choice += 4;
				count[3]++;
				break;
			case 5:
				fives += 5;
				choice += 5;
				count[4]++;
				break;
			case 6:
				sixes += 6;
				choice += 6;
				count[5]++;
				break;
			default:
				break;
			}
		}

		//FOUR OF A KIND
		if (ones >= 4 || twos >= 8 || threes >= 12 || fours >= 16 || fives >= 20 || sixes >= 24) {
			foak = choice;
		}
		//FULL HOUSE
		bool sameThree = false;
		bool sameTwo = false;
		int sameThreeDiceNum, sameTwoDiceNum; // 똑같은 3개의 주사위의 눈, 똑같은 2개의 주사위의 눈
		for (int i = 0; i < 6; i++) {
			if (count[i] == 3) {
				sameThree = true;
				sameThreeDiceNum = i + 1;
			}
			else if (count[i] == 2) {
				sameTwo = true;
				sameTwoDiceNum = i + 1;
			}
			else if (count[i] == 5) {
				sameThree = true;
				sameTwo = true;
				sameThreeDiceNum = i + 1;
				sameTwoDiceNum = i + 1;
			}
		}
		if (sameThree && sameTwo) {
			fh = (sameThreeDiceNum * 3) + (sameTwoDiceNum * 2);
		}

		//LITTLE STRAIGHT, BIG STRIAGHT
		int straightCount = 0;
		for (int i = 0; i < 6; i++) {
			if (count[i] > 0) {
				straightCount++;
			}
			else {
				straightCount = 0;
			}

			if (straightCount == 4) {
				ls = 15;
			}
			if (straightCount == 5) {
				bs = 30;
				
			}
		}

		//YACHT
		for (int i = 0; i < 6; i++) {
			if (count[i] == 5) {
				yacht = 50;
			}
		}
		int subtotal = ones + twos + threes + fours + fives + sixes;
		if (subtotal >= 63) {
			bonus = 35;
		}

		cout << "Ones : " << ones << endl;
		cout << "Twos : " << twos << endl;
		cout << "Threes : " << threes << endl;
		cout << "Fours : " << fours << endl;
		cout << "Fives : " << fives << endl;
		cout << "Sixes : " << sixes << endl;
		cout << "Subtotal : " << subtotal << endl;
		cout << "Bonus : " << bonus << " Bonus if subtotal is over 63" << endl;

		cout << "Choice : " << choice << endl;
		cout << "Four of a Kind : " << foak << endl;
		cout << "Full House : " << fh << endl;
		cout << "Little Straight : " << ls << endl;
		cout << "Big Straight : " << bs << endl;
		cout << "Yacht : " << yacht << endl;
		
		this->scores[0] = ones;
		this->scores[1] = twos;
		this->scores[2] = threes;
		this->scores[3] = fours;
		this->scores[4] = fives;
		this->scores[5] = sixes;
		this->scores[6] = choice;
		this->scores[7] = foak;
		this->scores[8] = fh;
		this->scores[9] = ls;
		this->scores[10] = bs;
		this->scores[11] = yacht;
		this->scores[12] = bonus;
	
	}

	const int* getScores() const {
		return scores;
	}

	void initialize() {
		stored_Die.clear();
	}

	Dice getDice(int index) {
		return stored_Die[index];
	}

	void roll() {
		for (int i = 0; i < NUMOFDICE; i++) {
			stored_Die[i].roll();
		}
	}
};