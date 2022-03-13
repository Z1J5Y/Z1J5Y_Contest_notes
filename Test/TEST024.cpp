#include<iostream>
#include<vector>
#include<algorithm>

struct aa
{
    int a;

    // bool operator>(aa b)
    // {
    //     return a<b.a;
    // }
};

class cmp
{
public:
    bool operator()(aa a,aa b)
    {
        return a.a<b.a;
    }
};
bool cc(int a,int b)
{
    return a>b;
}
int main()
{
    std::vector<aa> vec{{1},{3},{9},{6},{2},{8}};

    std::sort(vec.begin(),vec.end(),cmp());

    for(auto i=vec.begin();i!=vec.end();++i)
        std::cout<<i->a<<" ";
    return 0;
}