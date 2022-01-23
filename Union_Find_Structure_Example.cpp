//https://uoj.ac/problem/127
//https://www.luogu.com.cn/problem/P1955
//【NOI2015】程序自动分析

#include<bits/stdc++.h>

using ll = long long;

// const ll LEN =1e9+7;

// ll uf[LEN],rank[LEN];

std::vector<ll> check;

std::unordered_map<ll,ll> uf,rank;

void init()
{
	check.clear();
	rank.clear();
	uf.clear();
}

int find(int n)
{
	if(n==uf[n]) return uf[n];
	uf[n]=find(uf[n]);
	return uf[n];
}

void merge(int n1,int n2)
{
	int x=find(n1),y=find(n2);
	if(rank[x]>rank[y])
		uf[y]=x;
	else 
	{
		uf[x]=y;
		if(rank[x]==rank[y]) rank[y]++;
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);


	int T;
	std::cin>>T;
	while(T--)
	{
		init();
		int n;
		ll t1,t2,t3;
		std::cin>>n;
		bool flag=true;
		for(int i=0;i<n;++i)
		{
			std::cin>>t1>>t2>>t3;
			if(t1==t2&&t3==0) flag=false;
			if(uf[t1]==0) {uf[t1]=t1;rank[t1]=0;}
			if(uf[t2]==0) {uf[t2]=t2;rank[t2]=0;}
			if(t3)
				merge(t1,t2);
			else {check.push_back(t1);check.push_back(t2);}
		}
		if(!flag) {std::cout<<"NO\n";continue;}
		for(int i=0;i<check.size();i+=2)
		{
			if(find(check[i])==find(check[i+1])) {flag=false;break;}
		}
		if(flag) std::cout<<"YES\n";
		else std::cout<<"NO\n";
	}
	return 0;
}