#pragma once
#include<iostream>
#include<string>
using namespace std;

typedef struct Score {
	string name;
	int score;
	bool filled;	//해당 족보?가 채워졌는지 여부
}score;

class ScoreBoard {	// 한 사람당 점수판
private:
	string playerName;
	vector<score> scores;
	int totalScore;		

public:
	void initializeScoreBoard()		//어차피 모든 점수가 채워져야 되므로.. 점수 벡터 만들고 시작.
	{
		totalScore = 0;

		scores.push_back({"Ones",0,false});
		scores.push_back({ "Twos", 0, false });
		scores.push_back({ "Threes", 0,false });
		scores.push_back({ "Fours", 0 ,false });
		scores.push_back({ "Fives", 0 ,false });
		scores.push_back({ "Sixes", 0 ,false });

		scores.push_back({ "Four of a kind", 0,false });
		scores.push_back({ "Full House", 0 ,false });
		scores.push_back({ "Little Straight", 0,false });
		scores.push_back({ "Big Straight", 0,false });
		scores.push_back({ "Yacht", 0 ,false });
		scores.push_back({ "Choice", 0 ,false });

	}
	void updateScore() {

	}

	void bonusScore() {
		int bonus_sum = 0;
		for (int i = 0; i < 6; i++) {
			bonus_sum += scores[i].score;
		}
		if (bonus_sum >= 63) {
			totalScore += 35;
		}
	}

	int calTotalResult() {
		for (int i = 0; i < scores.size(); i++) {
			if(scores[i].filled)
				totalScore += scores[i].score;
		}
		return totalScore;
	}

	bool isFilledAll() {							//점수판의 모든 점수가 채워졌는지를 체크하여 반환.
		for (int i = 0; i < scores.size(); i++) {
			if (scores[i].filled == false)
				return false;
			return true;
		}
	}
};