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
	Score scores[12];		//���Ϳ��� �迭�� �ٲ���!
	int totalScore;		

public:
	ScoreBoard()		//������ ��� ������ ä������ �ǹǷ�.. ���� ���� ����� ����.
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

	bool isFilledAll() {							//�������� ��� ������ ä���������� üũ�Ͽ� ��ȯ, ���δ� ä�������� ���� ������Ѿ���
		for (int i = 0; i < 12; i++) {
			if (scores[i].filled == false)
				return false;
			return true;
		}
	}
};