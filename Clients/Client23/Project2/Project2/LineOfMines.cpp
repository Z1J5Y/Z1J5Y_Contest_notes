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
	srand((unsigned)time(NULL));							//��ʱ��Ϊ��,���������
	for (int i = 0; i < numberOfMines; ++i)
	{	
loop:	t = rand() % lineLength;							//����numberOfMines�����������������ظ����������������������
		for (int j = 0; j < i; ++j)
			if (t == mineLocations[j]) goto loop;
		mineLocations[i] = t;
	}
	std::sort(mineLocations.begin(), mineLocations.end());	//�����������(���׽϶�ʱ��Ч������(�Ǳ�Ҫ))
}
void LineOfMines::setCounts()//��Ϊ�������һ��͵�һ�� ���и��ӵĸ����������������Ҹ���� ���Խ���һ������һ������
{
	std::vector<int>::iterator it = std::find(mineLocations.begin(), mineLocations.end(), 1);	//����һ�񸽽�������
	if (it != mineLocations.end()) neighbouringMineCounts[0] = 1;
	
	it = std::find(mineLocations.begin(), mineLocations.end(), lineLength - 2);					//���һ�񸽽�������
	if (it != mineLocations.end()) neighbouringMineCounts[lineLength - 1] = 1;

	for (int i = 1; i < lineLength-1; ++i)														//�������ӵ�����
	{
		if ((it = std::find(mineLocations.begin(), mineLocations.end(), i+1)) != mineLocations.end()) neighbouringMineCounts[i]++;
		if ((it = std::find(mineLocations.begin(), mineLocations.end(), i-1)) != mineLocations.end()) neighbouringMineCounts[i]++;
	}
}
bool LineOfMines::containsMine(int v)
{
	auto it=std::find(mineLocations.begin(), mineLocations.end(), v - 1);						//Ѱ�Ҵ˴��Ƿ�����
	if (it != mineLocations.end()) return true;
	return false;
}
void LineOfMines::display()																		//ѭ�����
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
	for (int i = 0; i < numberOfMines; ++i)														//�����׵ĸ���ȫ����¶
		locationDisplays[mineLocations[i]][2] = '*';											//(�ı�display�����ֵ)
	display();
}
bool LineOfMines::hasHitMine()
{
	return hitMine;
}
int  LineOfMines::getScore()
{
	if (hitMine) return 0;																		//��������0��
	return score;
}
void LineOfMines::makeSelection(int a)
{
	int reveal = a - 1;																			//�����±��0��ʼ���� ���Գ�ʼ-1
	bool hasmine = containsMine(a);																//�жϴ˸��Ƿ�����
	if (!hasmine)																				//����
	{
		locationDisplays[reveal][2] = neighbouringMineCounts[reveal] + '0';
		score++;
	}
	else																						//����
	{
		
		hitMine = true;
		locationDisplays[reveal][2] = '*';
	}
}