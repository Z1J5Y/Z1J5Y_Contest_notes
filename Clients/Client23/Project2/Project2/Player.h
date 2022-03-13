#pragma once
#ifndef str
#include<string>
#define str
#endif // !str

class Player
{
private:
	std::string name;
	int bestScore;
public:
	Player(std::string v1);
	std::string getName();
	int getMaxScore();
	bool checkRecord(int score);
};