//顺序表实现顺序队
#include<stdio.h>
#include<stdlib.h>
#define INITIALSIZE 10
#define ADDSIZE 5


typedef struct queue
{
    int *rear,*front;
    int size;
}Queue;

int InitQueue(Queue *);
int enQueue(Queue *,int);
int deQueue(Queue *,int *);


int main()
{
    int t;
    Queue a;
    if(!InitQueue(&a)) exit(1);
    if(!enQueue(&a,1)) exit(1);
    if(!deQueue(&a,&t)) exit(1);
    return 0;
}
int InitQueue(Queue *a)
{
    (*a).rear=(*a).front=(int*)calloc(INITIALSIZE,sizeof(int));
    (*a).size=INITIALSIZE;
    if(!((*a).rear)) return 0;
}

int enQueue(Queue *a,int b)
{
    if((*a).front-(*a).rear>=(*a).size)
    {
        if(!((*a).rear=realloc((*a).front,((*a).size+ADDSIZE)*sizeof(int)))) return 0;
    }
    *((*a).rear++)=b;
    return 1;
}

int deQueue(Queue *a,int *b)
{
    if((*a).front==(*a).rear) return 0;
    *b=*(++(*a).front);
    return 1;
}