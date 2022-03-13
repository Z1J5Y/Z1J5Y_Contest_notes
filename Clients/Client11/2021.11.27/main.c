#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char p_words[2006][256];
char n_words[4783][256];
char article[2000][256];

int main()
{
    FILE* fp1;
    FILE* fp2;
    FILE* fp3;

    int number_positive = 0;
    int number_negative = 0;

    fp1 = fopen("positive-words.txt", "r");
    if (fp1 == NULL)
    {
        fprintf(stderr, "we cannot open the file\n");
        exit(1);
    }
    fp2 = fopen("negative-words.txt", "r");
    if (fp2 == NULL)
    {
        fprintf(stderr, "we cannot open the file\n");
        exit(1);
    }
    fp3 = fopen("cv001_19502.txt", "r");
    if (fp3 == NULL)
    {
        fprintf(stderr, "we cannot open the file\n");
        exit(1);
    }
    int count = 0;
    while (fgets(p_words[count], 256, fp1))
        count++;
    count = 0;
    while (fgets(n_words[count], 256, fp2))
        count++;

    //for (int i = 0; i < 2006; ++i)
    //    printf("%s", p_words[i]);

    count = 0;
    int length;
    while (!feof(fp3))
    {
        fscanf(fp3, "%s", article[count]);
        length = strlen(article[count]);
        article[count][length] = '\n';
        article[count][length + 1] = 0;
        count++;
    }
    int flag;
    for (int i = 0; i < count; ++i)
    {
        flag = 0;
        for (int j = 0; j < 2007; ++j)
        {
            if (!strcmp(article[i], p_words[j]))
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            number_positive++;
            continue;
        }
        for (int j = 0; j < 4783; ++j)
        {
            if (!strcmp(article[i], n_words[j]))
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            number_negative++;
            continue;
        }
    }


    if (number_positive > number_negative)
        printf("This review is positive");
    else
        printf("This review is positive");

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
}