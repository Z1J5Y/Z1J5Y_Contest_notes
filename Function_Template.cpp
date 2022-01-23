#include<iostream>

void Function(const int a,int &b)
{
    b=a;
}
void Function(int &a,int &b)
{
    a=b;
}

template<typename T>
void Function1(T &a,T &b)
{
    T temp=a;
    a=b;
    b=temp;
}

template<typename T>
T Function1(T &a,char b,int c=2)
{
    a=a+c;
    return (T)b+c;
}
int main()
{
    int a=1,b=2;
    char c='t';
    Function1(a,b);
    c=Function1(b,c);
    std::cout<<a<<' '<<b<<' '<<c<<std::endl;
    return 0;
}