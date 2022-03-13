#include"Range.h"
#include"Card.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

int main()
{
	std::cout << "Cars 2-10 are worth their numeric value." << std::endl;
	std::cout << "J,Q,K have a value of 11." << std::endl;
	std::cout << "An A has a value of 12 as a spade and 1 for other suits." << std::endl;
	std::cout << "Over 3 rounds, you will try to reach or exceed a target value, whithout going over 22!" << std::endl;
	std::cout << "If you go over, you get -1 points; if you are within range, you get +1 points; otherwise you get 0 points." << std::endl;

	int round = 3;
	std::string spade = "Spades", heart = "Hearts", diamond = "Diamonds", clud = "Clubs";
	
	int score = 0;								//total score
	int flag;									//point of every round
	while (round--)
	{
		srand((unsigned)time(NULL));
		int lower_bound = rand() % 6 + 17;		//generate random lower_bound(lower_bound is in [17,22])
		
		std::vector<Card> cards;				//create cards
		for (int i = 0; i < 36; ++i)
		{
			if (i % 4 == 0)
				cards.push_back(Card(spade, std::to_string(i / 4 + 2)));
			else if (i % 4 == 1)
				cards.push_back(Card(heart, std::to_string(i / 4 + 2)));
			else if (i % 4 == 2)
				cards.push_back(Card(diamond, std::to_string(i / 4 + 2)));
			else
				cards.push_back(Card(clud, std::to_string(i / 4 + 2)));
		}
		cards.push_back(Card(spade, "J"));
		cards.push_back(Card(spade, "Q"));
		cards.push_back(Card(spade, "K"));
		cards.push_back(Card(spade, "A"));
		cards.push_back(Card(heart, "J"));
		cards.push_back(Card(heart, "Q"));
		cards.push_back(Card(heart, "K"));
		cards.push_back(Card(heart, "A"));
		cards.push_back(Card(diamond, "J"));
		cards.push_back(Card(diamond, "Q"));
		cards.push_back(Card(diamond, "K"));
		cards.push_back(Card(diamond, "A"));
		cards.push_back(Card(clud, "J"));
		cards.push_back(Card(clud, "Q"));
		cards.push_back(Card(clud, "K"));
		cards.push_back(Card(clud, "A"));

		Card temp(dealCard(cards));				//default Copy constructor
		std::vector<Card> hand_cards;
		hand_cards.push_back(temp);				//player must have at least one card
		int hand_value=cardValue(temp);

		char judge = 'y';
		flag = 0;							//represent score you will get in this round

		std::cout << std::endl;

		while (!exceeds(22, hand_value))			//hand_value is less than 22
		{
			std::cout << "Target lower bound: " << lower_bound << std::endl;
			showHand(hand_cards, hand_value);
			std::cout << "Deal more? y/n: ";
			std::cin >> judge;
			if (judge == 'y')
			{
				Card temp(dealCard(cards));
				hand_cards.push_back(temp);
				hand_value += cardValue(temp);
				if (exceeds(22, hand_value))					//hand_value is greater than 22
				{
					flag = -1;
					std::cout << "Target lower bound: " << lower_bound << std::endl;
					showHand(hand_cards, hand_value);
					break;
				}
				else if (inRange(lower_bound, 22, hand_value))
				{
					flag = 1;
					std::cout << "Target lower bound: " << lower_bound << std::endl;
					showHand(hand_cards, hand_value);
					break;
				}
			}
			else break;
		}
		score += flag;
		if (flag == 1)
			std::cout << "You got " << flag << " point" << std::endl;
		else
			std::cout << "You got " << flag << " points" << std::endl;
	}
	if(score==1)
		std::cout << std::endl << "Your total score is " << score << " point.";
	else
		std::cout << std::endl << "Your total score is " << score << " points.";

	return 0;
}