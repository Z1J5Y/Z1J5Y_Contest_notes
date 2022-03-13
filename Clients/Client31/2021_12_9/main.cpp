#include<iostream>
#include<string>


class Word
{
public:
	Word(std::string name = "", std::string ex = "", std::string na = "", std::string t = "0", std::string k ="false");
	~Word();
	std::string getword();
	std::string getexplain();
	std::string getnature();
	std::string getkill();
	std::string gettimes();
	void display();
private:
	std::string word;
	std::string explain;
	std::string nature;
	std::string kill;
	std::string times;
};

Word::Word(std::string name, std::string ex, std::string na, std::string t, std::string k )
{
	word = name;
	explain = ex;
	nature = na;
	times = t;
	kill = k;
}
Word::~Word()
{
}
std::string Word::getkill()
{
	return kill;
}
std::string Word::gettimes()
{
	return times;
}
std::string Word::getword()
{
	return word;
}
std::string Word::getexplain()
{
	return explain;
}
std::string Word::getnature()
{
	return nature;
}
void Word::display()
{
	std::cout << "\n";
	std::cout << "word:" << word << std::endl;
	std::cout << "explaination:" << explain << std::endl;
	std::cout << "nature:" << nature << std::endl;
	std::cout << "killed:" << kill << std::endl;
	std::cout << "recite times:" << times << std::endl;
	std::cout << "\n";
}


class System
{
public:
	System(std::string n = "", int num = 0);
	~System();
	std::string getname();
	void addWord();
	void display();
	void queryword();
	void Init();
private:
	std::string name;
	Word words[100];
	int word_num;
};
System::System(std::string n ,int num)
{
	name = n;
	word_num = num;
}

System::~System()
{
}

std::string System::getname()
{
	return name;
}
void System::addWord()
{
	
	std::string name = ""; 
	std::string ex = ""; 
	std::string na = ""; 
	std::string t = "";
	std::string k = "false";
	std::cout << "\n";
	std::cout << "Input word:" << std::endl;
	std::cin >> name;
	std::cout << "Input explaination:" << std::endl;
	std::cin >> ex;
	std::cout << "If it has been killed?(1/0)" << std::endl;
	std::cin >> k;
	std::cout << "Input time you recite" << std::endl;
	std::cin >> t;
	std::cout << "Input the nature of the word" << std::endl;
	std::cin >> na;
	std::cout << "\n";
	Word a(name, ex, na, t, k);
	words[word_num++] = a;
}
void System::Init()
{
	int n;
	std::cout << "\n";
	std::cout << "Input num of words:" << std::endl;
	std::cin >> n;
	for (int i = 0; i < n; ++i) addWord();
	std::cout << "\n";
}
void System::display()
{
	std::cout << "\n";
	for (int i = 0; i < word_num; ++i)
		words[i].display();
	std::cout << "\n";
}
void System::queryword()
{
	std::string word;
	std::cout << "\n";
	std::cout << "Input the word you want to query" << std::endl;
	std::cin >> word;
	for (int i = 0; i < word_num; ++i)
	{
		if (words[i].getword() == word)
		{
			words[i].display();
			return;
		}
	}
	std::cout << "\n";
	std::cout << "There is not this word in the system." << std::endl;
}

void meau(System system)
{
	int s;
	while (1)
	{
		std::cout << "\n";
		std::cout << "1.Initialize System data." << std::endl;
		std::cout << "2.Add word" << std::endl;
		std::cout << "3.Display word data" << std::endl;
		std::cout << "4.Query word data" << std::endl;
		std::cout << "\n";
		std::cin >> s;
		switch (s)
		{
		case 0:
			return;
		case 1:
			system.Init();
			break;
		case 2:
			system.addWord();
			break;
		case 3:
			system.display();
			break;
		case 4:
			system.queryword();
			break;
		default:
			break;
		}
	}

	return ;
}





int main()
{
	std::string name;
	std::cout << "Input name of recite system" << std::endl;
	std::cin >> name;
	System system(name);
	meau(system);




	return 0;
}