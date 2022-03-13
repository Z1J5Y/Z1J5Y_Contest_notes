#include<vector>
#include<cstdlib>
#include<ctime>
#include<iostream>


void InitCards(std::vector<char>& cards)
{
	cards.clear();
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 4; ++j)
			cards.push_back(i + '0');
	for (int i = 0; i < 4; ++i) cards.push_back('J');
	for (int i = 0; i < 4; ++i) cards.push_back('Q');
	for (int i = 0; i < 4; ++i) cards.push_back('K');

}

bool findA(char player)
{
	if (player == '1') return true;
	return false;
}

int cardValue(char t)
{
	if (t >= '1' && t <= '9') return t - '0';
	return 10;
}

char dealCard(std::vector<char>& t)
{
	srand((unsigned)time(NULL));
	int select = rand() % t.size();
	char result = t[select];
	for (int i = select; i < t.size() - 1; ++i) t[i] = t[i + 1];
	t.pop_back();

	return result;
}

void showHand(std::vector<char>& t, int player)
{
	std::cout << "Player is: " << player << std::endl;
	std::cout << "Hand is: ";
	for (int i = 0; i < t.size(); ++i)
	{
		if (t[i] == '0') std::cout << 10 << " ";
		else if (t[i] == '1') std::cout << 'A' << " ";
		std::cout << t[i] << " ";
	}
		
	std::cout << std::endl;
}

