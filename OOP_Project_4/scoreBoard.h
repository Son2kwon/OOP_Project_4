#pragma once
#include<iostream>
#include<string>

#define NUMOFSCORES 12

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

		scores[6] = { "Choice",0,false };
		scores[7] = { "Four of a kind",0,false };
		scores[8] = { "Full House",0,false };
		scores[9] = { "Little Straight",0,false };
		scores[10] = { "Big Straight",0,false };
		scores[11] = { "Yacht",0,false };


	}

	score getScore(int n) {
		return scores[n];
	}

	void updateScore(const int *scoreArr) {			//어떤 점수에 기록할 건지 입력 받은 후, 점수를 저장(.
		cout << "어떤 점수에 기록할 것인지 선택하시오" << endl
			<< "1:Ones" << endl
			<< "2: Twos" << endl
			<< "3: Threes" << endl
			<< "4: Fours" << endl
			<< "5: Fives" << endl
			<< "6: Sixes" << endl
			<< "7: Choice" << endl
			<< "8: Four of a kind" << endl
			<< "9: Full House" << endl
			<< "10: Little Straight" << endl
			<< "11: Big Straight" << endl
			<< "12: Yacht" << endl<< endl
			<<"입력>> ";

		int n;
		cin >> n;
		while (scores[n - 1].filled) {
			cout << "이미 기록된 점수입니다. 다시 입력하세요" << endl << "입력>> ";
			cin >> n;
		}
		scores[n - 1].score = scoreArr[n - 1];
		scores[n - 1].filled = true;

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
		for (int i = 0; i < NUMOFSCORES; i++) {
			if(scores[i].filled)
				totalScore += scores[i].score;
		}
		return totalScore;
	}

	bool isFilledAll() {							//점수판의 모든 점수가 채워졌는지를 체크하여 반환, 전부다 채워졌으면 게임 종료시켜야함
		for (int i = 0; i < NUMOFSCORES; i++) {
			if (scores[i].filled == false)
				return false;
		}

		return true;
	}
	

};