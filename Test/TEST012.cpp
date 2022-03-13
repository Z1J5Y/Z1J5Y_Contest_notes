#include<bits/stdc++.h>



using ll = long long;
const ll LEN=1e6+7;
const ll MOD=1e8;
const int INF=INT_MAX;
const ll LLINF=LONG_LONG_MAX;

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}




int a[LEN],b[LEN],c[LEN];

void multi()
{
    for(int i=0;i<LEN;++i)
    {
        for(int j=0;j<=i;++j)
            c[i]+=a[i]*b[i-j];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
}

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::string t;
    std::cin>>t;
    std::reverse(t.begin(),t.end());
    for(int i=0;i<t.size();++i)
        a[i]=t[i]-'0';
    std::cin>>t;
    std::reverse(t.begin(),t.end());
    for(int i=0;i<t.size();++i)
        b[i]=t[i]-'0';
    multi();
    int i;
    for(i=LEN-1;c[i]==0;--i)
    if(i==-1) std::cout<<0;
    for(;i>=0;--i)
        std::cout<<c[i];



    return 0;
}
