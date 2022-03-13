//递归计算行列式
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 100

double *GetDeterminant(double *,int ,int );
double CalcuDeterminant(double *,int );

int main()
{
    double a[MAXSIZE]={0};
    double re;
    int i=0,n;

    printf("Input Order of Determinant:");
    scanf("%d",&n);
    printf("\nInput Data:");
    for(;i<n*n;) scanf("%lf",a+i++);

    re=CalcuDeterminant(a,4);
    printf("%lf ",re);

    return 0;
}
double *GetDeterminant(double *a,int b,int c)//a为传入行列式 b为所求行列式阶数 c为列
{
    int i,j,count=0;
    double *d=calloc(b*b,sizeof(double));

    for(i=1;i<b;++i)
    {
        for(j=0;j<b;++j)
        {
            if(j==c) continue;
            *(d+count++)=*(a+i*b+j);
            
        }
    }

    return d;
}

double CalcuDeterminant(double *a,int b)
{
    int i;
    double re=0,*t=NULL;

    if(b==2) return *(a)**(a+3)-*(a+1)**(a+2);
    for(i=0;i<b;++i)
    {
        t=GetDeterminant(a,b,i);
        re+=*(a+i)*pow(-1,i)*CalcuDeterminant(t,b-1);
        free(t);
    }

    return re;
}