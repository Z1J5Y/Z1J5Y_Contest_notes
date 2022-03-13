#include<stdio.h>
#include<string.h>

char stack[10000];

int main()
{
    int n,top=0;
    scanf("%d",&n);
    getchar();
    
    char opera[10];

    while(n--)
    {
        gets(opera);
        if(strlen(opera)==6)
            stack[top++]=opera[5];
        else if(strlen(opera)==5)
        {
            if(top)
            {
                for(int i=top-1;i>=0;--i)
                    printf("| %c |\n",stack[i]);
                printf("|===|\n");
            }
            else printf("Empty\n");
        }
        else
        {
            if(!strcmp("top",opera))
            {
                if(top)
                    printf("%c\n",stack[top-1]);
                else printf("Empty\n");
            }
            else
            {
                if(top) top--;
                else printf("Empty\n");
            }
        }
    }


    return 0;
}