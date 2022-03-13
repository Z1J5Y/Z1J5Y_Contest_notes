#include<stdio.h>


int BinarySearch(int *,int ,int );

int main()
{
    int a[10]={0,1,3,6,8,9,12,35,67,222};

    printf("%d ",BinarySearch(a,10,9));

    return 0;
}
int BinarySearch(int *a,int b,int c)
{
    int left=0,right=b-1,n=(left+right)/2;
    while(a[n]!=c&&left<right)
    {
        if(a[n]>c) right=n;
        else if(a[n]<c) left=n+1;
        n=(right+left)/2;
    }
    if(a[n]!=c) return -1;
    return n;
}