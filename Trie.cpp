#include<iostream>
#include<map>

struct Trie
{
    char data;
    std::map<char,Trie> tree;
};

void addword(Trie *&a,std::string b)
{
    Trie *t=a;
    for(int i=0;i<b.length();++i)
    {
        if(t->tree.find(b[i])==t->tree.end())
        {
            Trie temp;
            temp.data=b[i];
            t->tree.emplace(b[i],temp);
            t=&(t->tree.find(b[i])->second);
        }
        else
            t=&(t->tree.find(b[i])->second);
    }
}

bool findword(Trie *&a,std::string b)
{
    Trie *t=a;
    for(int i=0;i<b.length();++i)
    {
        if(t->tree.find(b[i])==t->tree.end())
            return false;
        else
            t=&(t->tree.find(b[i])->second);
    }
    return true;
}

int main()
{
    Trie *a=new Trie();

    addword(a,"word");
    addword(a,"wait");
    addword(a,"waaa");

    if(findword(a,"word")) std::cout<<"123";

    return 0;
}