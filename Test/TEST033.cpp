#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using namespace std;
const ll LEN=1e3+7;
const int INF=1e8;


vector<string> sub;
int n,m;
bool flag;
struct mm
{
    int l,r,k;
};
mm res[LEN];
int length;

void dfs(int level,int k,int num)
{
    if(k==m)
    {
        flag=true;
        length=level;
    }
    if(flag) return;
    int pos;
    int i;
    for(i=0;i<n;++i)
    {
        for(pos=0;pos<m-num;++pos)
        {
            if(sub[i].substr(pos,num)==sub[n].substr(k,num))
                break;
        }
        if(pos!=m-num+1) break;
    }
    if(pos!=m)
    {
        res[level].l=pos;
        res[level].r=pos+num;
        res[level].k=i;
    }
    else return;
    dfs(level+1,k+2,2);
    if(flag) return;
    dfs(level+1,k+3,3);
    if(flag) return;
}

void solve()
{
    flag=false;
    cin>>n>>m;
    sub.resize(n+1);
    for(int i=0;i<=n;++i)
        cin>>sub[i];

    int k=0;
    dfs(0,0,0);
    if(flag)
        for(int i=1;i<length;++i)
            cout<<res[i].l<<" "<<res[i].r<<" "<<res[i].k<<"\n";

}



int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    while(T--)
        solve();



    return 0;
}
