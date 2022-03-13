#include"Range.h"
#include<cstdlib>
#include<ctime>
#include<iostream>

int cardValue(Card t)
{
	if (t.card_as_string()[0] <= '9' && t.card_as_string()[0] >= '1')
		return std::stoi(t.card_as_string().substr(0, 2));
	else if (t.card_as_string()[0] == 'J') return 11;
	else if (t.card_as_string()[0] == 'Q') return 11;
	else if (t.card_as_string()[0] == 'K') return 11;
	else if (t.card_as_string()[0] == 'A')
	{
		if (t.card_as_string().substr(1) == "[Spades]") return 12;
		else return 1;
	}
}

Card dealCard(std::vector<Card>& t)
{
	srand((unsigned)time(NULL));
	int select = rand() % t.size();
	Card result(t[select]);
	for (int i = select; i < t.size() - 1; ++i) t[i] = t[i + 1];
	t.pop_back();

	return result;
}

void showHand(std::vector<Card>& t, int total)
{
	std::cout << "Hand value is: " << total << std::endl;
	std::cout << "Hand is: ";
	for (int i = 0; i < t.size(); ++i)
		std::cout << t[i].card_as_string() << " ";
	std::cout << std::endl;
}

bool exceeds(int max_hand_value, int hand_value)
{
	return hand_value > max_hand_value;
}

bool inRange(int lower_bound, int max_hand_value, int hand_value)
{
	return (hand_value <= max_hand_value && hand_value >= lower_bound);
}