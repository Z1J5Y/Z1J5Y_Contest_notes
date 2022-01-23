//https://loj.ac/p/130
//https://www.luogu.com.cn/problem/P3374
#include<bits/stdc++.h>

using ll=long long;
const ll LEN=1e6+7;

ll a[LEN],b[LEN];

ll lowbit(ll x)
{
    return x&(-x);
}

void init(int n)
{
    for(int i=1;i<=n;++i)
    {
        b[i]+=a[i];
        if(i+lowbit(i)<=n) b[i+lowbit(i)]+=b[i];
    }
}
void add(ll n,ll x,ll len)
{
    while(n<=len)
    {
        b[n]+=x;
        n+=lowbit(n);
    }
}

ll presum(ll x)
{
    ll res=0;
    while(x>0)
    {
        res+=b[x];
        x-=lowbit(x);
    }
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=n;++i) std::cin>>a[i];
    init(n);
    ll tag,x,y;
    std::__lg(1);
    while(m--)
    {
        std::cin>>tag>>x>>y;
        if(tag==1) {add(x,y,n);a[x]+=y;}
        else std::cout<<(presum(y)-presum(x-1))<<"\n";
    }

    return 0;
}