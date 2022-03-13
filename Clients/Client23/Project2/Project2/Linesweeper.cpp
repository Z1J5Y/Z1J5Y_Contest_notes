#include"Player.h"
#include"LineOfMines.h"
#include<iostream>

void play(size_t line_length, size_t num_mines, Player& test);

int main()
{
	std::cout << "This is agame of Linesweeper: mines are arranged on a line." << std::endl;
	std::cout << "You select a position to reveal what is there" << std::endl;
	std::cout << "For every safe location you reveal, you get +1 point" << std::endl;
	std::cout << "If you reveal a mine, you get a score of 0" << std::endl;
	std::cout << "A given location may have a mine to either its left, rightm both, or neither." << std::endl;
	std::cout << "The number of neighbouring mines of a revealed location 0 / 1 / 2 if displayed." << std::endl;
	std::cout << "You can continue playing until you either hit a mine or choose not to reveal any more locations." << std::endl;

	std::cout << "What is your name ? ";
	std::string temp;
	getline(std::cin, temp);														//获取整行字符
	int line_length, num_mines;
	std::cout << "How long do you want the line?";
	std::cin >> line_length;
	std::cout << "How many mines do you want on the line?";
	std::cin >> num_mines;

	Player test(temp);																//创建一个Player对象实例
	char judge = 'y';																//继续游戏的标志
	while (judge == 'y')
	{
		play(line_length, num_mines, test);
		std::cout << "Would you like to play another game? [y/n]" << std::endl;		//游戏结束后问是否再进行
		std::cin >> judge;
	}
	std::cout << std::endl << test.getName() << ", your top score was " << test.getMaxScore();

	return 0;
}
void play(size_t line_length, size_t num_mines,Player &test)						//游戏的主体框架
{
	//std::cout << "This is agame of Linesweeper: mines are arranged on a line."<<std::endl;
	//std::cout << "You select a position to reveal what is there" << std::endl;
	//std::cout << "For every safe location you reveal, you get +1 point" << std::endl;
	//std::cout << "If you reveal a mine, you get a score of 0" << std::endl;
	//std::cout << "A given location may have a mine to either its left, rightm both, or neither." << std::endl;
	//std::cout << "The number of neighbouring mines of a revealed location 0 / 1 / 2 if displayed." << std::endl;
	//std::cout << "You can continue playing until you either hit a mine or choose not to reveal any more locations." << std::endl;
	
	
	
	
	//std::cout << "What is your name ? ";
	//std::string temp;
	//std::cin >> temp;
	//int line_length, num_mines;
	//std::cout << "How long do you want the line?";
	//std::cin >> line_length;
	//std::cout << "How many mines do you want on the line?";
	//std::cin >> num_mines;

	//Player test(temp);
	LineOfMines mine(line_length, num_mines);
	
	mine.display();
	int location_temp;
	char judge = 'y';
	while (judge=='y')
	{
		std::cout << "What position location would you like to reveal?";
		std::cin >> location_temp;
		mine.makeSelection(location_temp);
		
		if (mine.hasHitMine())
		{
			std::cout << "The mine positions are now revealed:\n";
			mine.grandReveal();
			
			break;
		}
		else
		{
			mine.display();
			std::cout << "Would you like to reveal another location?[y/n]";
			std::cin >> judge;
		}
	}
	if (test.checkRecord(mine.getScore()))
		std::cout << "You have a new high score of " << mine.getScore() << "!" << std::endl;
	else
		std::cout << "You scored " << mine.getScore() << ", but your best score is still " << test.getMaxScore() << std::endl;

	return ;
}