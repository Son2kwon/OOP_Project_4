#pragma once
#include<iostream>
#include<string>
using namespace std;

typedef struct Score {
	string name;
	int score;
	bool filled;	//�ش� ����?�� ä�������� ����
}score;

class ScoreBoard {	// �� ����� ������
private:
	string playerName;
	vector<score> scores;
	int totalScore;		

public:
	void initializeScoreBoard()		//������ ��� ������ ä������ �ǹǷ�.. ���� ���� ����� ����.
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

	bool isFilledAll() {							//�������� ��� ������ ä���������� üũ�Ͽ� ��ȯ.
		for (int i = 0; i < scores.size(); i++) {
			if (scores[i].filled == false)
				return false;
			return true;
		}
	}
};