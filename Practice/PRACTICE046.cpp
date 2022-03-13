#include<iostream>
class b
{
private:
    int a=1;
};

class a
{
private:
    int f=1;
    double s=2;
    float t=3;
public:
    a(int firstval,double secondval=3,float thirdval=4)
    {
        f=firstval;
        s=secondval;
        t=thirdval;
    }
    a()
    {
        std::cout<<"invoke a()"<<std::endl;
    }
    void print()
    {
        std::cout<<f<<' '<<s<<' '<<t<<std::endl;
    }
};

int main()
{
    a testc1;
    a testc2=a();

    a testc3[3]{a(1),a(2),a(3)};
    testc1.print();
    testc2.print();
    for(int i=0;i<3;++i)
    {
        testc3[i].print();
    }
    return 0;
}