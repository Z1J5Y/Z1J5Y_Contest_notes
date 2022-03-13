#include<iostream>
#include<set>
#include<string>
//定义函数对象模板类
class cmp
{
public:
    int a;
    //重载 () 运算符
    cmp(int v);
    friend bool operator<(const cmp &a, const cmp &b);
};
cmp::cmp(int v)
{
    a=v;
}
bool operator<(const cmp &a, const cmp &b)
{
        //按照值的大小，做升序排序
        int la=std::to_string(a.a).length(),lb=std::to_string(b.a).length();
        return  la < lb;
}

int main()
{
    std::set<int> a{12,123,1234,1,12345};
    for(auto it=a.begin();it!=a.end();++it)
        printf("%d ",*it);
    return 0;
}