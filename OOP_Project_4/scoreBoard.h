#pragma once
#include<iostream>
#include<string>
using namespace std;

typedef struct Score {
	string name;
	int score;
}score;

class ScoreBoard {	// 한 사람당 점수판
private:
	string playerName;
	vector<score> scores;
	int totalScore;

public:
	void updateScore() {

	}

	void bonusScore() {

	}

	void calTotalResult() {

	}
};