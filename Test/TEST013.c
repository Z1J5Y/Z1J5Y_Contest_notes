#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int size(int a[])
{
	return sizeof(a)/sizeof(a[1]);
}

int main()
{
	// char *a=NULL,*b=a;
	// b=(char *)malloc(10*sizeof(char));
	// memset(a,0,10*sizeof(char));
	// for(int i=0;i<10;i++)
	// {
	// 	printf("%d ",*(a+1));
	// }
	// free(a);
	int a[10];
	printf("%d",size(a));
	return 0;
}