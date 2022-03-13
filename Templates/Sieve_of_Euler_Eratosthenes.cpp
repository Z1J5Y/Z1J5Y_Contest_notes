//https://www.luogu.com.cn/problem/P1217
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

const ll LEN=1e8+7;

int a,b;

bool flag[LEN];
std::vector<ll> primes;
void Eratothenes()
{
	for(ll i=3;i*i<=LEN;++i)
		if(!flag[i])
			for(ll j=i*i;j<=LEN;j+=i)
				flag[j]=true;
}
void Euler()
{
	for (ll i = 2; i <= b; ++i)
	{
		if (!flag[i])
			primes.push_back(i);
		for (ll j = 0; j < primes.size() && i * primes[j] < b; ++j)
		{
			flag[i * primes[j]] = true;
			if (i % primes[j] == 0)
				break;
		}
	}
}
bool palindrome(int n)
{
	string a(to_string(n));
	string b=a;
	reverse(a.begin(),a.end());
	return a==b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>a>>b;
    if (b>=10000000)
        b=10000000;
	if(a%2==0) ++a;
	Euler();
	for(auto i=lower_bound(primes.begin(),primes.end(),a);*i<=b&&i!=primes.end();++i)
		if(palindrome(*i))
			cout<<*i<<"\n";

	return 0;
}