#include<bits/stdc++.h>



using ll = long long;
const ll LEN=1e6+7;
const ll MOD=1e8;
const int INF=INT_MAX;
const ll LLINF=LONG_LONG_MAX;

template<class T>
inline void read(T &x)
{
    T f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    x*=f;
}



int k[LEN];

int main()
{
    // freopen("in","r",stdin);
    freopen("in","w",stdout);

    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);

    
    for(int i=0;i<LEN;++i)
    {
        std::cout<<rand();
    }






    return 0;
}
