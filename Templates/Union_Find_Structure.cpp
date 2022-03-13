#include<bits/stdc++.h>

using ll=long long;
const ll LEN=1e7+7;

ll rank[LEN],UF[LEN];

void init()
{
    for(int i=0;i<LEN;++i)
    {
        rank[i]=0;
        UF[i]=i;
    }
}

ll find(int n)
{
    if(UF[n]==n) return UF[n];
    UF[n]=find(UF[n]);
    return UF[n];
}
void merge(int n1,int n2)
{
    int x=find(n1);
    int y=find(n2);
    if(rank[x]>rank[y])
        UF[y]=x;
    else
    {
        UF[x]=y;
        if(rank[x]==rank[y]) rank[y]++;
    }
}

int main()
{



    return 0;
}