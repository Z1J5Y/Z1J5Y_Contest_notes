#include<bits/stdc++.h>



using ll = long long;
const ll LEN=2e5+7;
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

int a[LEN];
std::deque<std::deque<int>> k;
int b[LEN];
std::map<int,bool> mp;
int cur;
int n;

int findmax()
{
    int max;
    mp.clear();
    for(int i=cur;i<n;++i)
    {
        mp[a[i]]=true;
    }
    for(int i=0;i<=(mp.rbegin()->first+1);++i)
    {
        if(mp[i]==false)
        {
            max=i;
            break;
        }
    }
    int t,maxi=cur;
    for(int i=0;i<max;++i)
    {
        // t=k[i][];
        
        if(t>maxi) maxi=t;
    }

    cur=maxi+1;
    return max;
}

void solve()
{
    cur=0;
    k.clear();
    k.resize(LEN);
    std::cin>>n;
    int t;
    for(int i=0;i<n;++i)
    {
        std::cin>>a[i];
        k[a[i]].push_back(i);
    }
    int cnt=0;
    while(cur!=n)
    {
        b[++cnt]=findmax();
    }
    std::cout<<cnt<<"\n";
    for(int i=1;i<=cnt;++i)
    {
        std::cout<<b[i]<<" ";
    }
    std::cout<<"\n";


}

int main()
{
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
