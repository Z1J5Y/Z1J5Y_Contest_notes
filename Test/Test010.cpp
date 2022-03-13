#include<iostream>

void c(int &a,float b=4)
{
    a=b;
}

int main()
{
    int b=2;
    int *const a=&b;
    *a=3;
    int const *d=&b;
    //*d=1 INVALID
    //c(b);
    std::cout<<*a;

    return 0;
}