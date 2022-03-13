#include<stdio.h>

char a[100007];
char stack[100007];

int BracketMatchTest()
{
    int top=0;
    int i;
    char temp = 0;
    for (i = 0; a[i]; i++)
    {
        switch (a[i])
        {
            case '(':
            case '[':
            case '{':
                stack[top++]=a[i];
                break;
            case ')':
            case ']':
            case '}':
                if (top==0)
                    return 0;
                temp=stack[--top];
                if (temp == '(' && a[i] != ')')
                    return 0;
                if (temp == '[' && a[i] != ']')
                    return 0;
                if (temp == '{' && a[i] != '}')
                    return 0;
                break;
            default: return 0;
        }
    }
    if(!top) return 1;
    return 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        int flag=BracketMatchTest();
        if(flag) printf("True\n");
        else printf("False\n");
    }

    return 0;
}