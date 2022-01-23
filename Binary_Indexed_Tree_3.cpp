//https://loj.ac/p/132
#include<bits/stdc++.h>

using ll=long long;
const ll LEN=1e6+7;

ll a[LEN],b[LEN],c[LEN];

ll lowbit(ll x)
{
    return x&(-x);
}

void init(int n)
{
    for(int i=1;i<=n;++i)
    {
        b[i]+=a[i];
        c[i]+=i*a[i];
        if(i+lowbit(i)<=n)
        {
            b[i+lowbit(i)]+=b[i];
            c[i+lowbit(i)]+=c[i];
        }
            
    }
}
void add(ll n,ll x,ll len)
{
    ll t=n;
    while(n<=len)
    {
        b[n]+=x;
        c[n]+=t*x;
        n+=lowbit(n);
    }
}

ll presum(ll x)
{
    ll res=0,t=x;
    while(x>0)
    {
        res+=(t+1)*b[x]-c[x];
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
            std::cin>>x>>y;
            std::cout<<presum(y)-presum(x-1)<<"\n";
        }
    }

    return 0;
}