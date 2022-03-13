#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const ll LEN=2000;


int n,res;
int s[30];
int a[30],b[30],c[30],d[30];

bool check(int k,int level)
{
    if(level==1) return true;
    if(a[k]||b[k]||c[k+level]||d[k-level+n])
        return false;
    return true;
}

void dfs(int k,int level)
{
    s[level]=k;
    if(level==n)
    {
        res++;
        return ;
    }
    for(int i=1;i<=n;++i)
    {
        if(check(i,level+1))
        {
            a[i]=1;
            b[i]=1;
            c[i+level+1]=1;
            d[i-level-1+n]=1;
            dfs(i,level+1);
            a[i]=0;
            b[i]=0;
            c[i+level+1]=0;
            d[i-level-1+n]=0;
        }
    }
}


int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    while(!(cin>>n).eof())
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        memset(s,0,sizeof(s));
        res=0;
        dfs(0,0);
        cout<<res<<"\n";
    }
    
    return 0;
}