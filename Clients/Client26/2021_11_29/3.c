#include <stdio.h>
#include <math.h>

int Max[107];
int array[107];

int main()
{
    int n, max_index = 0;
    int result = -1;
    int count = 0;
    do
    {
        scanf("%d", &array[count++]);
        if (array[count - 1] > array[max_index])
            max_index = count - 1;

    } while (getchar() != '\n');

    int lowermax = array[0], highermax = array[count - 1];
    for (int i = 0; i < max_index; ++i)
    {
        if (lowermax < array[i])
            lowermax = array[i];
        Max[i] = abs(array[max_index] - lowermax);
        if (result < Max[i])
            result = Max[i];
    }
    for(int i=count-1;i>max_index;--i)
    {
        if(highermax<array[i])
            highermax=array[i];
        Max[i]=abs(array[max_index]-highermax);
        if(result<Max[i])
            result=Max[i];
    }

    printf("%d", result);

    return 0;
}