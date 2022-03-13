#include<iostream>

struct test1
{
    int a,b,c;
};

struct test2
{
    int a;
    int c;
    int b;
};

void test(int a[])
{
    printf("%p\n",a);
}

int main()
{
    // char b;
    // std::string a;
    // int c;
    // std::cin>>a;
    // // std::cin.ignore();

    // std::cin>>b;
    // std::cin>>c;
    // std::cout<<a<<std::endl<<b<<std::endl<<c;
    test1 t1{1,2,3};
    test2 t2={1,2,3};
    int a{2};
    std::cout<<t1.a<<" "<<t1.b<<" "<<t1.c<<"\n";
    std::cout<<t2.a<<" "<<t2.b<<" "<<t2.c<<"\n";
    std::cout<<a<<"\n";

    int b[10]{0,1,2,3,4,5,6,7,8,9};
    std::cout<<b<<"\n";
    test(b);
    printf("%p\n",b);
    return 0;
}