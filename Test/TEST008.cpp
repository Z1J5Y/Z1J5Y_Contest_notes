#include<iostream>

namespace a
{
    int abc;
    double gk;
}

namespace b
{
    float abc;
    int gk=2;
}
int main()
{
    using namespace a;
    abc=0;
    std::cout<<abc<<' '<<gk<<std::endl;
    int abc=2;
    std::cout<<abc<<' '<<gk;

    return 0;
}