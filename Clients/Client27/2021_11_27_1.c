#include<stdio.h>

int main()
{
    int x,n;
    double sum,S;
    scanf("%d%d",&x,&n);
    for(int i=1;i<=n;++i)
    {
        sum=0;
        for(int j=0;j<=i;++j)
            sum+=j;
        S+=1.0*x/sum;
    }
    printf("%lf",S);


    return 0;
}