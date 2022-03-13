#include<iostream>
#include<vector>


class SumPower
{
public:
    int operator()(int data,int pow)
    {
        int result=1;
        for(int i=0;i<pow;++i)
            result*=data;
        return result;
    }
};
template<class func>
int power(int data,int pow,func p)
{
    return p(data,pow);
}

int main()
{
    std::vector<int> test;
    
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    int init=0;
    for(int i=0;i<test.size();++i)
        init+=power(test[i],3,SumPower());
    std::cout<<init;

    return 0;
}