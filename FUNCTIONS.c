#include<stdio.h>
//选择排序
void Selection_sort(float array[], int n)
{
	float b;
	for (int i = 0; i < n; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (array[j] > array[k])
			{
				k = j;
			}
		}
		if (k != i)
		{
			b = array[i];
			array[i] = array[k];
			array[k] = b;
		}
	}
}
//冒泡排序
void Bubble_sort(float array[],int n)
{
    float b;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(array[j]>array[j+1])
            {
                b=array[i];
                array[i]=array[j];
                array[j]=b;
            }
        }
    }
}
//数组元素的下表(二分法查找)
int search(float array[], int n, float m)
{
	int a;
	int min, max;
	min = 0;
	max = n - 1;
	for (; array[(min + max) / 2] != m;)
	{
		if (array[(min + max) / 2] > m)
		{
			max = (min + max) / 2-1;
		}
		else if (array[(min + max) / 2] < m)
		{
			min = (min + max) / 2+1;
		}
	}
	a = (min + max) / 2;
	return a;
}
//判断素数(返回1)
int isprime(int a)
{
    if(a==1) return 0;
    for(int i=2;i*i<=a;++i)
        if(a%i==0) return 0;
    return 1;
}//链表排序案例(标准为month)
struct date
{
    int year;
    int month;
    int day;
    struct date *next;
};
typedef struct date Date;
Date *Sort(Date *head)
{
    Date *pCure=NULL,*temp,*current;
    for(;head->next!=pCure;pCure=current->next)
    {
        current=head;
        for(;current->next->next!=pCure;current=current->next)
        {
            if(current->next->month>current->next->next->month)
            {
                temp=current->next->next->next;
                current->next->next->next=current->next;
                current->next=current->next->next;
                current->next->next->next=temp;
            }
        }
    }
    return head;
}

