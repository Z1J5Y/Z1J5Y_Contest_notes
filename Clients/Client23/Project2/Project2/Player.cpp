#include"Player.h"

Player::Player(std::string v1)
{
	name = v1;
	bestScore = 0;
}

std::string Player::getName()
{
	return name;
}
int Player::getMaxScore()
{
	return bestScore;
}
bool Player::checkRecord(int score)
{
	if (score > bestScore) bestScore = score;
	else return false;
	return true;
}