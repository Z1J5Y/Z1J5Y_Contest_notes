#include<iostream>

void swap(int a[],int i1,int i2){int t=a[i1];a[i1]=a[i2];a[i2]=t;}

void HeapAdjust(int a[],int low,int high)
{
    int t=a[low];
    for(int i=2*low;i<high;i=i*2)
    {
        if(!i&&i<high-1) i++;
        if(i<high-1&&a[i]<a[i+1]) i++;
        if(t>=a[i]) break;
        a[low]=a[i];
        low=i;
    }
    a[low]=t;
}

void HeapSort(int a[],int low,int high)
{
    for(int i=high/2;i>=low;--i)
        HeapAdjust(a,i,high);
    for(int i=high-1;i>=1;--i)
    {
        swap(a,low,i);
        HeapAdjust(a,low,i);
    }

}

int main()
{
    int a[]={0,9,5,10,4,3,6,2,12,8,1,11};
    HeapSort(a,0,12);
    for(int i=0;i<12;++i) printf("%d ",a[i]);

    return 0;
}