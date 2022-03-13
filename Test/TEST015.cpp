#include<iostream>

template<class Type>
class array1
{
public:
    Type arr[20][20];
};

int main()
{
    array1<int> a;
    for(int i=0;i<20;++i)
        for(int j=0;j<20;++j)
            a.arr[i][j]=i+j;
    for(int i=0;i<20;++i)
    {
        for(int j=0;j<20;++j)
            printf("%d ",a.arr[i][j]);
        putchar('\n');
    }
    int different[400],flag=0;
    a.arr[0][0]=100;
    a.arr[1][0]=99;
    a.arr[0][1]=101;
    int cont=0;
    for(int i=0;i<20;++i)
        for(int j=0;j<20;++j)
        {
            for(int k=0;k<cont;++k)
            {
                if(a.arr[i][j]==different[k])
                {
                    flag=1;
                    break;
                }
            }
            if(!flag) different[cont++]=a.arr[i][j];
        }
    printf("%d\n",cont);
    for(int i=0;i<cont;++i)
    {
        printf("%d ",different[i]);
    }

    return 0;
}