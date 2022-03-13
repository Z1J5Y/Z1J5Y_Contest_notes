#include<stdio.h>

int array[1000][1000];
int col[1000];
int row[1000];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int maxc=0,maxr=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            scanf("%d",&array[i][j]);
            if(array[i][j]>col[j])
            {
                col[j]=array[i][j];
                if(col[j]>maxc) maxc=col[j];
            }
            if(array[i][j]>row[i])
            {
                row[i]=array[i][j];
                if(row[i]>maxr) maxr=row[i];
            }
        }
    }
    for(int i=maxc;i>0;--i)
    {
        for(int j=0;j<m;++j)
        {
            if(col[j]>=i)
                printf("*");
            else 
                printf(" ");
        }
        printf("\n");
    }
    printf("\n");
    for(int i=maxr;i>0;--i)
    {
        for(int j=0;j<n;++j)
        {
            if(row[j]>=i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}