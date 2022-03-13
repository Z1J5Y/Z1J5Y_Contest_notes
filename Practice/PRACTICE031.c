//P119.6
//循环队列
#include<stdio.h>
#include<stdlib.h>
#define INITSIZE 10
typedef struct queue
{
    int num[INITSIZE];
    int rear,front;
}Queue;

void InitQueue(Queue *);
int enQueue(Queue *,int );
int deQueue(Queue *,int *);
void TraversQueue(Queue *);


int main()
{
    Queue a={{0},0,0};
    int sign=0,num;
    
    do
    {
        printf("\nNUM.1 ADD PATIENT TO THE QUEUE");
        printf("\nNUM.2 THE FIRST PATIENT IN THE QUEUE GO TO SEE A DOCTOR");
        printf("\nNUM.3 CHECK THE QUEUE");
        printf("\nNUM.4 LIST THE REST OF PATIENT AND SEE A DOCTOR IN ORDER");
        printf("\nNUM.5 QUIT");

        printf("\nInput num:");
        scanf("%d",&sign);
        switch (sign)
        {
        case 1:
            printf("Input the num of patient");
            scanf("%d",&num);
            enQueue(&a,num);
            break;
        
        case 2:
            deQueue(&a,&num);
            printf("A PATIENT GO TO SEE A DOCTOR.\nPATIENT NUM:%d ",num);
            break;
        
        case 3:
            TraversQueue(&a);
            break;
        
        case 4:
            while(!deQueue(&a,&num))
            {
                printf("%d ",num);
            }
            break;
        
        case 5:
            printf("\nQUIT");
            break;
        default:
            printf("\nInput error");
            printf("PLS INPUT AGAIN");
            break;
        }
    }while(sign!=5);
    
    return 0;
}

void InitQueue(Queue *a)
{
    (*a).rear=(*a).front=0;
}

int enQueue(Queue *a,int b)
{
    if(((*a).rear+1)%INITSIZE==(*a).front) return 1;
    (*a).rear=((*a).rear+1)%INITSIZE;
    (*a).num[(*a).rear]=b;
    return 0;
}

int deQueue(Queue *a,int *b)
{
    if((*a).rear==(*a).front) return 1;
    (*a).front=((*a).front+1)%INITSIZE;
    (*b)=(*a).num[(*a).front];
    return 0;
}

void TraversQueue(Queue *a)
{
    int t=(*a).front;
    for(;(*a).rear!=t;)
    {
        t=(t+1)%INITSIZE;
        printf("%d ",(*a).num[t]);
    }
    return;
}