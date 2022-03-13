#include<stdio.h>
#include<math.h>

int main()
{
    int a[4];
    scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
    for(int i=0;i<4;++i)
    {
        int t=i;
        for(int j=i+1;j<4;++j)
            if(a[t]>a[j]) t=j;
        if(t!=i)
        {
            int temp=a[t];
            a[t]=a[i];
            a[i]=temp;
        }
    }
    for(int i=0;i<4;++i)
        printf("%d ",a[i]);
    putchar('\n');
    for(int i=3;i>=0;--i)
        printf("%d ",a[i]);

    return 0;
}