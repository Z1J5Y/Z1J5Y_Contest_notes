#include<iostream>
#include<map>

struct st
{
    int a,b,c;

    friend bool operator<(st a,st b);
};

bool operator<(st a,st b)
{
    if(a.a!=b.a)
        return a.a<b.a;
    else if(a.b!=b.b)
        return a.b<b.b;
    else
        return a.c<b.c;
}

int main()
{
    std::map<int,std::string,std::greater<int>> a;
    a.insert({0,"first"});
    a.emplace(1,"second");
    a.insert({
        {5,"fifth"},
        {4,"forth"}
            });
    a.insert(std::pair<int,std::string>{9,"ninth"});
    for(std::map<int,std::string>::iterator iter=a.begin();iter!=a.end();++iter)
        std::cout<<iter->first<<' ';
    std::cout<<'\n';

    std::map<st,int> b;
    st temp{1,2,3};
    b.insert({temp,1});//1 2 3
    temp.c=2;
    b.emplace(temp,2);//1 2 2
    temp.b=1;
    b.insert({temp,3});//1 1 2
    temp.a=0;
    b.insert({temp,4});//0 1 2
    b.insert(std::pair<st,int>{temp,5});
    for(std::map<st,int>::iterator iter=b.begin();iter!=b.end();++iter)
        std::cout<<iter->second<<' ';
    std::cout<<'\n';

    std::multimap<st,int> c;
    st tem{1,2,3};
    c.insert({tem,1});//1 2 3
    temp.c=2;
    c.emplace(tem,2);//1 2 2
    temp.b=1;
    c.insert({tem,3});//1 1 2
    temp.a=0;
    c.insert({tem,4});//0 1 2
    c.insert(std::pair<st,int>{tem,5});
    for(std::multimap<st,int>::iterator iter=c.begin();iter!=c.end();++iter)
        std::cout<<iter->second<<' ';
    std::cout<<'\n';

    return 0;
}