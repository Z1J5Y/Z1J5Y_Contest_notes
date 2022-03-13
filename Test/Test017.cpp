#include <iostream>

class Mark
{
private:
    int Math;
public:
    Mark(int a=0);
    void Display();
    ~Mark();
    // Mark operator+(const Mark &a)const;
    friend Mark operator+(const Mark &a,const Mark &b);
};

Mark::Mark(int a)
{
    Math=a;
}
Mark::~Mark()
{
    std::cout<<"Destructor!"<<std::endl;
}
// Mark Mark::operator+(const Mark &a) const
// {
//     Mark N(a.Math+Math);
//     return N;
// }
void Mark::Display()
{
    std::cout<<"Mark of math is "<<Math<<std::endl;
}
Mark operator+(const Mark &a,const Mark &b)
{
    Mark N(a.Math+b.Math);
    return N;
}
int main()
{
    Mark s1(85),s2(73);
    (s1+s2).Display();

    return 0;
}