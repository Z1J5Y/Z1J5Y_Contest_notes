#include<vector>

void InitCards(std::vector<char>& cards);

bool findA(char player);

int cardValue(char t);

char dealCard(std::vector<char>& t);

void showHand(std::vector<char>& t, int total);