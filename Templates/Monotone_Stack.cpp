//https://www.luogu.com.cn/problem/P2866
#include<bits/stdc++.h>

using ll = long long;
using namespace std;
const ll LEN=8e4+7;


inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

deque<ll> a;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n,t;
    n=read();
    ll ans=0;
    for(int i=0;i<n;++i)
    {
        t=read();
        while(!a.empty()&&a.back()<=t)
            a.pop_back();
        ans+=a.size();
        a.push_back(t);
    }
    cout<<ans;
	return 0;
}