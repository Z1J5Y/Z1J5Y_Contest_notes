#include<stdio.h>
#include<stdlib.h>

void hanoi(int ,char ,char ,char );
void move(int ,char ,char);

int main()
{
    hanoi(3,'A','B','C');
    return 0;
}

void hanoi(int n,char x,char y,char z)
{
    if(n==0) return;
    hanoi(n-1,x,z,y);
    move(n,x,z);
    hanoi(n-1,y,x,z);
}

void move(int n,char from,char to)
{
    printf(" move %d from %c to %c\n",n,from,to);
}