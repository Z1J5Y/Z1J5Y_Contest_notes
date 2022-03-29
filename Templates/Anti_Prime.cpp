//https://www.acwing.com/problem/content/description/200/
//https://www.luogu.com.cn/problem/P1463
//https://codeforces.com/problemset/problem/27/E
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

ll k[LEN];
ll primes[]{2,3,5,7,11,13,17,19,23,29};

ll N;
ll maxi,res;
void dfs(int now,int m,int y,int index)
{
    if(m>maxi||m==maxi&&now<res)
    {
        maxi=m;
        res=now;
    }
    if(index==10)
        return ;
    for(int i=1;i<=y;++i)
    {
        now*=primes[index];
        if(now>N)
            return;
        dfs(now,m*(i+1),i,index+1);
    }
}

signed main()
{
    PPP();

    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::cin>>N;
    dfs(1,1,32,0);
    std::cout<<res;




    return 0;
}
