#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>

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






int main()
{
	std::cout << "Cars 2-10 are worth their numeric value and 10 is represented by number '0'" << std::endl;
	std::cout << "J,Q,K have a value of 10." << std::endl;
	std::cout << "An A has a value of 1/11." << std::endl << std::endl;
	std::cout << "Player 1~7 represent players and 0 represent banker" << std::endl;
	std::cout << "Press Enter to continue. " << std::endl;
	getchar();
	



	std::vector<char> cards;
	std::vector<int> total_score;
	int take;
	std::vector<std::vector<char>> player_cards(8);
	std::vector<bool> boom;
	char judge = 'y';

	while (judge=='y')
	{
		InitCards(cards);
		boom.clear();
		boom.resize(8);
		total_score.clear();
		take = 0;
		for (int i = 0; i < 8; ++i)
		{
			player_cards[i].push_back(dealCard(cards));
			player_cards[i].push_back(dealCard(cards));
			total_score.push_back(cardValue(player_cards[i][0]) + cardValue(player_cards[i][1]));
		}
		

		char ju = 'n';

		std::cout << "One of banker's card: " << player_cards[0][0] << std::endl<<std::endl;
		for (int i = 1; i < 8; ++i)
		{
			showHand(player_cards[i], i);
			std::cout << "Total score " << total_score[i] << std::endl;
			std::cout << "If player " << i << " wants to get a card? [y/n]";
			std::cin >> ju;
			if (ju == 'y')
			{
				player_cards[i].push_back(dealCard(cards));
				std::cout << "New card " << player_cards[i][2] << std::endl;
				total_score[i] += cardValue(player_cards[i][2]);
			}
			std::cout << std::endl;
		}

		showHand(player_cards[0], 0);
		if (total_score[0] <= 16)
		{
			std::cout << "Banker's score is less than 16, he must take another card" << std::endl;
			player_cards[0].push_back(dealCard(cards));
			total_score[0] += cardValue(player_cards[0][2]);
			std::cout << "New card " << player_cards[0][2] << std::endl;
		}

		if (total_score[0] > 21)
		{
			std::cout << "The banker lose, and win players: ";
			for (int i = 1; i < 8; ++i) if (total_score[i] <= 21) std::cout << std::endl << "player " << i;
			std::cout << std::endl;
			std::cout << "The banker lose, and draw players: ";
			for (int i = 1; i < 8; ++i) if (total_score[i] > 21) std::cout << std::endl << "player " << i;
		}
		else
		{
			for (int i = 1; i < 8; ++i)
				if (total_score[i] <= 21)
				{
					boom[i] = true;
					int temp = 0;
					for (int j = 0; j < player_cards[i].size(); ++j)
						if (findA(player_cards[i][j]))
							temp += 10;
					total_score[i] += temp;
				}
			for (int i = 0; i < player_cards[0].size(); ++i)
				if (findA(player_cards[0][i]))
					total_score[0] += 10;

			for (int i = 1; i < 8; ++i)
			{
				if (!boom[i]) std::cout << "Player " << i << " lose." << std::endl;
				else
				{
					if(total_score[i]<total_score[0]) std::cout << "Player " << i << " lose." << std::endl;
					else if (total_score[i] > total_score[0]) std::cout << "Player " << i << " win." << std::endl;
					else std::cout << "Player " << i << " draw." << std::endl;
				}
			}
		}

		std::cout << std::endl << "Would like to play an other round? [y/n]" << std::endl;
		std::cin >> judge;
	}


	return 0;
}