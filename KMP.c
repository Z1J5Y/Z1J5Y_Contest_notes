#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long KMPPos(char *, char *);
int* GetNextImproved(char *,int );

int main()
{
    char String[1000001] ={0};
    int num;
    long count;

    gets(String);
    scanf("%d", &num);
    getchar();

    char pattern[100001] = {0};

    for (long i = 0; i < num; ++i)
    {
        count = 0;
        gets(pattern);
        count = KMPPos(String, pattern);
        if (count) printf("%s\n", (String + count-1));
        else printf("Not Found\n");
    }
    return 0;
}

long KMPPos(char *m,char *s)
{
    long i=0,j=0;
    long ml=strlen(m),sl=strlen(s);
    int *next=GetNextImproved(s,sl);

    while(i<ml&&j<sl)
    {
        if(m[i]==s[j]||j==-1)
        {
            ++i,++j;
        }
        else
        {
            j=next[j];
        }
    }
    free(next);

    if(j>=sl) return i-sl;
    else return 0;
}

int* GetNextImproved(char *s,int length)
{
    int *next=(int *)calloc(length,sizeof(int));
    int i=0,j=-1;
    next[0]=-1;

    while(i<length)
    {
        if(j==-1||s[i]==s[j])
        {
            ++i,++j;
            if(s[i]==s[j]) next[i]=next[j];
            else next[i]=j;
        }
        else j=next[j];
    }

    return next;
}