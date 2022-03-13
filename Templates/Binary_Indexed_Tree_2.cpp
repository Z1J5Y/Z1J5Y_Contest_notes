//https://loj.ac/p/131
//https://www.luogu.com.cn/problem/P3368
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

    int n,m,t,tt=0;
    std::cin>>n>>m;
    for(int i=1;i<=n;++i) {std::cin>>t;a[i]=t-tt;tt=t;}
    init(n);
    ll tag,x,y,k;
    while(m--)
    {
        std::cin>>tag;
        if(tag==1) 
        {
            std::cin>>x>>y>>k;
            add(x,k,n);
            add(y+1,-k,n);
        }
        else
        {
            std::cin>>x;
            std::cout<<presum(x)<<"\n";
        }
    }

    return 0;
}