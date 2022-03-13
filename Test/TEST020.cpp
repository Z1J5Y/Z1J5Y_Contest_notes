#include<iostream>
#include<map>
#include<array>
#include<algorithm>
int main()
{
    std::map<int,int> a;
    std::pair<int,int> pair1(1,2);
    a.insert(pair1);
    a.insert(pair1={2,2});
    a[7]=7;
    for(auto it=a.begin();it!=a.end();++it) std::cout<<(*it).first<<' '<<(*it).second<<std::endl;
    std::cout<<pair1.first<<' '<<pair1.second<<std::endl;
    int array[10]{};
    std::array<int,10> arr{};
    for(auto it=arr.begin();it!=arr.end();++it)
        std::cout<<(*it)<<' ';
    std::cout<<std::endl;
    arr={1,2,3,4,5,6,7,8,9,0};
    for(auto it=arr.begin();it!=arr.end();++it)
        std::cout<<(*it)<<' ';
    std::cout<<std::endl;
    std::cout<<*std::lower_bound(arr.begin(),arr.end(),3)<<std::endl;
    std::cout<<*std::upper_bound(arr.begin(),arr.end(),3)<<std::endl;
    std::cout<<a.upper_bound(1)->first<<' '<<a.upper_bound(1)->second<<std::endl;
    std::cout<<a.lower_bound(1)->first<<' '<<a.lower_bound(1)->second<<std::endl;
    return 0;
}