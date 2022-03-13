#include<bits/stdc++.h>

using ll = long long;
const ll LEN=1e3+7;
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

std::vector<std::vector<std::pair<int,int>>> graph(LEN);//(edge,weight)
int n,m;
int res=0;
bool flag=true;

void solve()
{
    std::vector<int> vex(LEN,0),min(LEN,INF);
    min[1]=0;
    vex[1]=1;
    for(int i=0;i<graph[1].size();++i)
    {
        min[graph[1][i].first]=graph[1][i].second;
        vex[graph[1][i].first]=1;
    }
    for(int i=2;i<=n;++i)
    {
        int mn=INF;
        int j=2,k;
        for(;j<=n;++j)
        {
            if(min[j]!=0&&min[j]<mn)
            {
                mn=min[j];
                k=j;
            }
        }
        res+=min[k];
        min[k]=0;
        for(j=0;j<graph[k].size();++j)
        {
            if(min[graph[k][j].first]!=0&&min[graph[k][j].first]>graph[k][j].second)
            {
                min[graph[k][j].first]=graph[k][j].second;
                vex[graph[k][j].first]=k;
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(min[i]==INF)
        {
            flag=false;
        }
    }
}

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);

    
    std::cin>>n>>m;
    int t1,t2,t3;
    for(int i=1;i<=m;++i)
    {
        std::cin>>t1>>t2>>t3;
        graph[t1].push_back(std::make_pair(t2,t3));
        graph[t2].push_back(std::make_pair(t1,t3));
    }
    solve();
    if(flag)
    {
        std::cout<<res;
    }
    else std::cout<<"-1";



    return 0;
}