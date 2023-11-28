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
	Score scores[12];		//벡터에서 배열로 바꿨음!
	int totalScore;		

public:
	ScoreBoard()		//어차피 모든 점수가 채워져야 되므로.. 점수 벡터 만들고 시작.
	{
		totalScore = 0;

	
		scores[0]={ "Ones",0,false };
		scores[1] = { "Twos",0,false };
		scores[2] = { "Threes",0,false };
		scores[3] = { "Fours",0,false };
		scores[4] = { "Fives",0,false };
		scores[5] = { "Sixes",0,false };

		scores[6] = { "Four of a kind",0,false };
		scores[7] = { "Full House",0,false };
		scores[8] = { "Little Straight",0,false };
		scores[9] = { "Big Straight",0,false };
		scores[10] = { "Yacht",0,false };
		scores[11] = { "Choice",0,false };


	}

	score getScore(int n) {
		return scores[n];
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
		for (int i = 0; i < 12; i++) {
			if(scores[i].filled)
				totalScore += scores[i].score;
		}
		return totalScore;
	}

	bool isFilledAll() {							//점수판의 모든 점수가 채워졌는지를 체크하여 반환, 전부다 채워졌으면 게임 종료시켜야함
		for (int i = 0; i < 12; i++) {
			if (scores[i].filled == false)
				return false;
			return true;
		}
	}
};