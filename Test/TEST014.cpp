#include<iostream>

class test
{
private:
    int money;
    double rate;
public:
    test(int ,double);
    double end();
    const test &com1(const test&) const;
    const test &com2(const test&) const;
    int com(const test &) const;
    friend void show(const test &);
    test operator-();
};

test test::operator-()
{
    return test(-money,-rate);
}

void show(const test &a)
{
    std::cout<<a.money<<' '<<a.rate<<std::endl;
}

test::test(int m=2,double ra=3.2)
{
    money=m;
    rate=ra;
}
int test::com(const test &s) const
{
    if(s.money==money) return 1;
    else return 0;
}
const test &test::com1(const test &s) const
{
    std::cout<<s.money<<' '<<money<<std::endl;
    if(s.money>money)
        return s;
    else
        return *this;
}

const test &test::com2(const test &s) const
{
    std::cout<<s.money<<' '<<money<<std::endl;
    return s.money>money?s:*this;
}

double test::end()
{
    return money*rate;
}

int main()
{
    int *a=new int[10];
    test test1;
    // std::cout<<test1.end()<<std::endl;
    // test test2(1,2);
    // if(test1.com(test1.com1(test2))==test1.com(test1.com2(test2)))
    //     std::cout<<"11111"<<std::endl;
    // if(test2.com(test2.com1(test1))==test2.com(test2.com2(test1)))
    //     std::cout<<"22222"<<std::endl;

    // test test3;
    // test3=test2;
    // test3=test();

    // if(test3.com(test3.com1(test2))==test3.com(test2.com2(test3)))
    //     std::cout<<"33333"<<std::endl;

    show(test1);
    // show(test2);
    // show(test3);
    // show(test1);
    // show(-test1);
    return 0;
}