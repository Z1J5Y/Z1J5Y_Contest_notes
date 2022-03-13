#include"LineOfMines.h"
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<iostream>

LineOfMines::LineOfMines(size_t v1, size_t v2)
{
	lineLength = v1;
	numberOfMines = v2;
	score = 0;
	locationDisplays.resize(lineLength);
	for (int i = 0; i < lineLength; ++i)
		locationDisplays[i] = "_____";
	neighbouringMineCounts.resize(lineLength);
	mineLocations.resize(numberOfMines);
	hitMine = false;
	placeMines();
	setCounts();
}
void LineOfMines::placeMines()
{
	int t;
	srand((unsigned)time(NULL));							//以时间为种,产生随机数
	for (int i = 0; i < numberOfMines; ++i)
	{	
loop:	t = rand() % lineLength;							//产生numberOfMines个随机数如果生成了重复的数字则重新生成随机数
		for (int j = 0; j < i; ++j)
			if (t == mineLocations[j]) goto loop;
		mineLocations[i] = t;
	}
	std::sort(mineLocations.begin(), mineLocations.end());	//给随机数排序(在雷较多时对效率有益(非必要))
}
void LineOfMines::setCounts()//因为除了最后一格和第一格 所有格子的附近雷数都由其左右格决定 所以将第一格和最后一格特判
{
	std::vector<int>::iterator it = std::find(mineLocations.begin(), mineLocations.end(), 1);	//看第一格附近的雷数
	if (it != mineLocations.end()) neighbouringMineCounts[0] = 1;
	
	it = std::find(mineLocations.begin(), mineLocations.end(), lineLength - 2);					//最后一格附近的雷数
	if (it != mineLocations.end()) neighbouringMineCounts[lineLength - 1] = 1;

	for (int i = 1; i < lineLength-1; ++i)														//其它格子的雷数
	{
		if ((it = std::find(mineLocations.begin(), mineLocations.end(), i+1)) != mineLocations.end()) neighbouringMineCounts[i]++;
		if ((it = std::find(mineLocations.begin(), mineLocations.end(), i-1)) != mineLocations.end()) neighbouringMineCounts[i]++;
	}
}
bool LineOfMines::containsMine(int v)
{
	auto it=std::find(mineLocations.begin(), mineLocations.end(), v - 1);						//寻找此处是否有雷
	if (it != mineLocations.end()) return true;
	return false;
}
void LineOfMines::display()																		//循环输出
{
	for (int i = 1; i < lineLength + 1; ++i)
		std::cout << i << "     ";
	std::cout << std::endl;
	for (int i = 0; i < lineLength; ++i)
		std::cout << locationDisplays[i] << " ";
	std::cout << std::endl;
}
void LineOfMines::grandReveal()
{
	for (int i = 0; i < numberOfMines; ++i)														//将有雷的格子全部揭露
		locationDisplays[mineLocations[i]][2] = '*';											//(改变display数组的值)
	display();
}
bool LineOfMines::hasHitMine()
{
	return hitMine;
}
int  LineOfMines::getScore()
{
	if (hitMine) return 0;																		//踩中雷则0分
	return score;
}
void LineOfMines::makeSelection(int a)
{
	int reveal = a - 1;																			//数组下标从0开始计数 所以初始-1
	bool hasmine = containsMine(a);																//判断此格是否有雷
	if (!hasmine)																				//无雷
	{
		locationDisplays[reveal][2] = neighbouringMineCounts[reveal] + '0';
		score++;
	}
	else																						//有雷
	{
		
		hitMine = true;
		locationDisplays[reveal][2] = '*';
	}
}