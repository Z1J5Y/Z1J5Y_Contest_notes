//https://www.luogu.com.cn/problem/P1168
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
const ll LEN=1e6+7;
const ll MOD=1e8;
const int INF=INT_MAX;
const ll LLINF=LONG_LONG_MAX;
const double eps=1e-8;

// ll k[LEN];

signed main()
{
    PPP();

    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::priority_queue<ll,std::vector<ll>,std::greater<ll>> l;
    std::priority_queue<ll,std::vector<ll>,std::less<ll>> r;
    ll n,t;
    std::cin>>n;
    for(int i=1;i<=n;++i)
    {
        std::cin>>t;
        if(r.empty())
        {
            r.emplace(t);
        }
        else if(r.top()<t)
        {
            l.emplace(t);
        }
        else
        {
            r.emplace(t);
        }
        while(std::abs(ll(l.size()-r.size()))>1)
        {
            if(l.size()>r.size())
            {
                r.emplace(l.top());
                l.pop();
            }
            else
            {
                l.emplace(r.top());
                r.pop();
            }
        }
        if(i&1)
        {
            std::cout<<(l.size()>r.size()?l.top():r.top())<<"\n";
        }
    }


    return 0;
}
