#include<iostream>
#include<string>
#include<vector>
char *tolower(char *a)
{
    for(int i=0;a[i]!=0;++i)
    {
        if(a[i]>='A'&&a[i]<='Z')
            a[i]+='a'-'A';
    }
    return a;
}

int main()
{
    // std::string t;
    // long result=0;
    
    // std::cin>>t;
    // for(char temp:t)
    // {
    //     result+=temp-'0';
    // }
    // std::cout<<result;
    std::string a;
    a.resize(20);
    a="as";
    std::cout<<a<<" "<<a.length()<<std::endl;
    std::vector<int> b(10,2);
    std::cout<<b.size()<<" "<<b.capacity()<<" "<<b.empty()<<" "<<b.front()<<std::endl;
    std::cout<<toupper('a');
    char wq[20]="qweqweASDASDASD";
    std::cout<<tolower(wq);
    return 0;
}