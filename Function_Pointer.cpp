#include<iostream>
#include<cmath>

int s(int );

int main()
{
    double b=4;
    int (*a)(int) = s;
    std::cout<<a(b)<<std::endl;

    return 0;
}
int s(int a)
{
    std::cout<<a<<std::endl;
    return sqrt(a);
}