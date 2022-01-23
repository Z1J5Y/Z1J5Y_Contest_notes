#include<iostream>
#include<cstring>

int cnt[1000];

template<class T>
void swap(T a[],T i1,T i2){T t=a[i1];a[i1]=a[i2];a[i2]=t;}


void CountingSort(int a[],int b[],int length)
{

    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<length;++i)
        cnt[a[i]]++;
    for(int i=0;i<1000;++i)
        cnt[i]+=cnt[i-1];
    for(int i=0;i<length;++i)
        b[--cnt[a[i]]]=a[i];

}


int main()
{
    int a[]={17,9,5,10,10,3,6,2,12,0,8,11};
    int b[12];
    CountingSort(a,b,12);
    for(int i=0;i<12;++i) printf("%d ",b[i]);

    return 0;
}