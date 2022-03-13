#include<stdio.h>
#include<string.h>
#define MAXLETTERNUM 26

long Sunday(char *String, char *pattern)
{
    if (String==NULL||pattern==NULL)
        return 0;

    long i,pos=0;
    long len_s,len_p;
    long letters[MAXLETTERNUM]={0};

    len_s = strlen(String);
    len_p = strlen(pattern);

    for (i=0;i<MAXLETTERNUM;i++)
        letters[i]=len_p+1;

    for (i=0;i<len_p;i++)
        letters[pattern[i]-97]=len_p-i;

    for (pos=0;pos<=len_s-len_p;)
    {
        for (i=0;pattern[i]==String[pos+i];)
        {
            i++;
            if (i>=len_p)
                return pos+1;
        }
        pos+=letters[String[pos+len_p]-97];
    }
    return 0;
}