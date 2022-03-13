#include<stdio.h>

int BF(char *,char *);


int main()
{
    char M[20];
    char S[10];

    gets(M);
    gets(S);
    printf("%d ",BF(M,S));

    return 0;
}

int BF(char *m,char *s)
{
    int j,i;
    for(i=0;m[i]!=0;++i)
    {
        if(m[i]==s[0])
        {
            for(j=0;s[j]!=0;++j)
            {
                if(m[i+j]!=s[j]) break;
            }
            if(s[j]==0) return i;
        }
    }
    return -1;
}
