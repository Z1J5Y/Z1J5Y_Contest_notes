#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
// using namespace std;
const ll LEN=1e2+7;
const int INF=INT_MAX;
const ll LLINF=LONG_LONG_MAX;


int k[LEN][32];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);

    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        std::cin>>k[i][0];
    }
    for(int j=1;j<=std::__lg(n);++j)
        for(int i=1;i+(1<<j)-1<=n;++i)
            k[i][j]=std::max(k[i][j-1],k[i+(1<<(j-1))][j-1]);
    int l,r;
    for(int i=0;i<m;++i)
    {
        std::cin>>l>>r;
        int s=std::__lg(r-l+1);
        std::cout<<std::max(k[l][s],k[r-(1<<s)+1][s])<<"\n";
    }

    return 0;
}