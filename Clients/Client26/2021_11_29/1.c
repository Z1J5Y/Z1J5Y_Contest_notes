#include<stdio.h>

int l[10000];
int v[10000];

int main()
{
    int n,L;
    int value=0;
    scanf("%d%d",&n,&L);
    for(int i=0;i<n;++i)
        scanf("%d",&v[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&l[i]);

    for(int i=0;i<n;++i)
    {
        int k=i;
        for(int j=i+1;j<n;++j)
            if(v[j]>v[k]) k=j;
        if(k!=i)
        {
            int temp1=v[i];
            v[i]=v[k];
            v[k]=temp1;
            int temp2=l[i];
            l[i]=l[k];
            l[k]=temp2;
        }
    }

    for(int i=0;i<n;++i)
    {
        if(L>=l[i])
        {
            value+=l[i]*v[i];
            L-=l[i];
        }
        else
        {
            value+=v[i]*L;
            L=0;
        }
        if(L==0) break;
    }

    printf("%d",value);


    return 0;
}