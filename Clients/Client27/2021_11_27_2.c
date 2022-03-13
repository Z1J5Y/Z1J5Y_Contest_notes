#include<stdio.h>
#include<math.h>

int main()
{
    double a,b,c,p;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(a+b<=c||a+c<=b||b+c<=a)
    {
        printf("不构成三角形");
        return 0;
    }
    p=(a+b+c)/2;
    double area=sqrt(p*(p-a)*(p-b)*(p-c));
    if(a==b||a==c||b==c)
    {
        if(a==b&&b==c)
            printf("构成等边三角形\n");
        else
            printf("构成等腰三角形\n");
    }
    else
    {
        printf("构成普通三角形\n");
    }
    printf("%.2lf",area);


    return 0;
}