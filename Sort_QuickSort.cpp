#include<iostream>
template<class T>
void swap(T a[],T i1,T i2){T t=a[i1];a[i1]=a[i2];a[i2]=t;}


void QuickSort(int a[],int l,int r)
{
    int right=r,left=l;
    int mid=a[(r+l)/2];
    do
    {
        while(a[left]<mid) left++;
        while(a[right]>mid) right--;
        if(left<=right) {swap(a,left,right);left++;right--;}
    }while(right>=left);

    if(l<right) QuickSort(a,l,right);
    if(left<r) QuickSort(a,left,r);
}


int main()
{
    int a[]={17,9,5,10,10,3,6,2,12,0,8,11};
    QuickSort(a,0,11);
    for(int i=0;i<12;++i) printf("%d ",a[i]);

    return 0;
}