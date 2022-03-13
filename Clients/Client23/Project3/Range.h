#include"Card.h"
#include<vector>

int cardValue(Card t);

Card dealCard(std::vector<Card>& t);

void showHand(std::vector<Card>& t, int total);

bool exceeds(int max_hand_value, int hand_value);

bool inRange(int lower_bound, int max_hand_value, int hand_value);