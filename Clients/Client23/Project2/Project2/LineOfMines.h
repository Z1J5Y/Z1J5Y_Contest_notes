#pragma once
#ifndef str
#include<string>
#define str
#endif // !str

#include<vector>

class LineOfMines
{
private:
	size_t lineLength;
	size_t numberOfMines;
	int score;
	std::vector<std::string> locationDisplays;
	std::vector<int> neighbouringMineCounts;
	std::vector<int> mineLocations;
	bool hitMine;


public:
	LineOfMines(size_t v1,size_t v2);
	void placeMines();
	void setCounts();
	bool containsMine(int v);
	void display();
	void grandReveal();
	bool hasHitMine();
	int getScore();
	void makeSelection(int a);

};


