#include<bits/stdc++.h>

using ll = long long;

// const ll LEN =1e6+7;


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	ll a,b,mod;
	std::cin>>a>>b>>mod;
	ll t=1,tb=b,ta=a;
	while(tb)
	{
		if(tb&1) t=t*ta%mod;
		ta=ta*ta%mod;
		tb>>=1;
	}
	std::cout<<a<<"^"<<b<<" mod "<<mod<<"="<<t;

	return 0;
}