//https://www.luogu.com.cn/problem/P3812
#include<bits/stdc++.h>
#define int ll

void PPP()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
#endif
}
using ll = long long;
const ll LEN=70+7;
const ll MOD=1e8;
const int INF=INT_MAX;
const ll LLINF=LONG_LONG_MAX;
const double eps=1e-8;

ll k[LEN];

void get(ll t)
{
    for(int i=62;i>=0;--i)
    {
        if((t>>i)&1ll)
        {
            if(k[i])
            {
                t^=k[i];
            }
            else
            {
                k[i]=t;
                return ;
            }
        }
    }
}

ll get_max()
{
    ll res=0;
    for(int i=62;i>=0;--i)
    {
        if((res^k[i])>res)
            res^=k[i];
    }
    return res;
}




signed main()
{
    PPP();

    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);

    int n,t;
    std::cin>>n;
    for(int i=0;i<n;++i)
    {
        std::cin>>t;
        // std::cout<<std::bitset<70>(t)<<"\n";
        get(t);
    }
    std::cout<<get_max();




    return 0;
}
