#include<iostream>
using namespace std;

void Function1(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void Function1(char &a)
{
    a='b';
}//函数重载
void Function2(int &a,int &b,void (*c)(int&,int&))
{
    c(a,b);
}//回调函数
int main()
{
    char c='6';
    int a=1,b=2;
    void (*d)(int&,int&)=&Function1;//函数指针

    Function1(a,b);
    Function2(a,b,d);
    d(a,b);
    cout<<a<<' '<<b<<endl;

    Function1(c);
    cout<<c<<endl;

    return 0;
}