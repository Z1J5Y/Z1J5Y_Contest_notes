#include<iostream>

typedef struct NODE
{
    int a;
}Node[10];

template<class T1,class T2>
void swap(T1 &a,T2&b)
{
    T2 t=a;
    a=b;
    b=t;
}

int main()
{
    int a=1;
    double b=2;
    swap(a,b);
    std::cout<<a<<' '<<b;
    return 0;
}