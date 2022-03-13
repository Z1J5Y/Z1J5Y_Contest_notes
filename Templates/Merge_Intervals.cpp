//https://codeforces.com/contest/1626/problem/C
#include<bits/stdc++.h>


void PPP()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    freopen("out","w",stdout);
#endif
}
using ll = long long;
const ll LEN=1e2+7;
const ll MOD=1e8;
const int INF=INT_MAX;
const ll LLINF=LONG_LONG_MAX;
const double eps=1e-8;

ll k[LEN];
ll h[LEN];
std::pair<ll,ll> qj[LEN];

void solve()
{
    int n;
    std::cin>>n;
    for(int i=0;i<n;++i)
        std::cin>>k[i];
    for(int i=0;i<n;++i)
        std::cin>>h[i];

    for(int i=0;i<n;++i)
    {
        qj[i].first=k[i]-h[i]+1;
        qj[i].second=k[i];
    }
    std::sort(qj,qj+n);
    ll l=0,r=0,res=0;
    for(int i=0;i<n;++i)
    {
        if(qj[i].first<=r)
        {
            r=std::max(r,qj[i].second);
        }
        else
        {
            if(r||l)
                res+=(r-l+1)*(r-l+2)/2;
            l=qj[i].first;
            r=qj[i].second;
        }
    }
    res+=(r-l+1)*(r-l+2)/2;
    std::cout<<res<<"\n";
}

int main()
{
    PPP();
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);


    int T;
    std::cin>>T;
    while(T--)
    {
        solve();
    }





    return 0;
}
