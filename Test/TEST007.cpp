#include<bits/stdc++.h>

int main()
{
    freopen("dataout.txt","r",stdin);
    freopen("dataout2.txt","w",stdout);

    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    time_t start,end;
    int t;
    start=time(NULL);
    for(int i=0;i<1e7;++i)
        std::cin>>t;
        // scanf("%d",&t);
        
    for(int i=0;i<1e7;++i)
        // printf("%d\n",i);
        std::cout<<i<<"\n";
    end=time(NULL);

    std::cout<<"\n"<<end-start;

    return 0;
}