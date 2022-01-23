#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INITSIZE 1000000
#define ADDSIZE 1000
#define MAXLETTERNUM 26

int Sunday(char *, char *);

int main()
{
    char *String = (char *)calloc(INITSIZE, sizeof(char));
    char t = 0;
    int num;
    long count = 0;

    do
    {
        t = getchar();
        ++count;
        *(String + count - 1) = t;
    } while (t != '\n');
    *(String + --count) = 0;

    scanf("%d", &num);
    getchar();

    char *pattern[10] = {0};

    for (int i = 0; i < num; ++i)
    {
        count = 0;
        pattern[i] = (char *)calloc(INITSIZE, sizeof(char));
        do
        {
            t = getchar();
            ++count;
            *(pattern[i] + count - 1) = t;
        } while (t != '\n');
        *(pattern[i] + --count) = 0;
    }
    for (int i = 0; i < num; ++i)
    {
        count = sunday(String, pattern[i]);
        if (count)
            printf("%s\n", (String + count-1));
        else
            printf("Not Found\n");
    }

    return 0;
}

int sunday(const char *src, const char *des)
{
    int i, pos = 0;
    int len_s, len_d;
    int alphabet[MAXLETTERNUM] = {0};

    if (src == NULL || des == NULL)
        return -1;

    len_s = strlen(src);
    len_d = strlen(des);

    for (i = 0; i < MAXLETTERNUM; i++)
        alphabet[i] = len_d;

    for (i = 0; i < len_d; i++)
        alphabet[des[i]-97] = len_d - i - 1;

    for (pos = 1; pos <= len_s - len_d;)
    {
        for (i = pos - 1; i - pos + 1 < len_d; i++)
        {
            if (src[i] != des[i - pos + 1])
                break;
        }

        if ((i - pos + 1) == len_d)
            return pos;
        else
            pos += alphabet[src[pos + len_d - 1]-97] + 1;
    }

    return 0;
}
