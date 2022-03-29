//HDU 3949 XOR
//交不了
//线性基求第k小的值
//关键在于rebuild()

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
const ll LEN=70;
const ll MOD=1e8;
const int INF=INT_MAX;
const ll LLINF=LONG_LONG_MAX;
const double eps=1e-8;

ll k[LEN],bk[LEN];
ll T=1;
ll cnt;
void insert(ll a)
{
    for(int i=63;i>=0;--i)
    {
        if((a>>i)&1)
        {
            if(!k[i])
            {
                k[i]=a;
                return ;
            }
            else
                a^=k[i];
        }
    }
}
ll query(ll a)
{
    ll res=0;
    for(int i=0;i<=63;++i)
    {
        if((a>>i)&1)
        {
            res^=bk[i];
        }
    }
    return res;
}
void rebuild()
{
    for(int i=63;i>=0;--i)
        if(k[i])
            for(int j=i-1;j>=0;--j)
                if(!k[j]&&((k[i]>>j)&1))
                    k[i]^=k[j];
    for(int i=0;i<=62;++i)
        if(k[i])
            bk[cnt++]=k[i];
}


void solve()
{
    memset(k,0,sizeof(k));
    memset(bk,0,sizeof(bk));
    cnt=0;
    int n,t;
    std::cin>>n;
    for(int i=0;i<n;++i)
    {
        std::cin>>t;
        insert(t);
    }
    int m;
    std::cin>>m;
    rebuild();
    std::cout<<"Case #"<<T++<<":\n";
    while(m--)
    {
        std::cin>>t;
        t-=(cnt!=n);
        if(t>=(1<<cnt))
            std::cout<<-1<<"\n";
        else
            std::cout<<query(t)<<"\n";
    }

}

signed main()
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
