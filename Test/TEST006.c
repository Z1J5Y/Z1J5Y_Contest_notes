#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    char sample[81]={0},hex[81]={0};
    int loc,i,j=0;
    long result=0;
    short flag=0;
    gets(sample);

    for(i=0;sample[i]!='#';++i)
        if((sample[i]>='0'&&sample[i]<='9')||(sample[i]<='f'&&sample[i]>='a')||(sample[i]<='F'&&sample[i]>='A'))
        {
            if(j==0) loc=i;
            hex[j]=sample[i];
            ++j;
        }

    for(i=0;i<loc;++i) if(sample[i]=='-') flag=1;

    for(int t=0,i=strlen(hex)-1;i>=0;--i,++t)
        if(hex[i]>='0'&&hex[i]<='9') result+=(hex[i]-48)*pow(16,t);
        else if(hex[i]<='f'&&hex[i]>='a') result+=(hex[i]-97+10)*pow(16,t);
        else result+=(hex[i]-65+10)*pow(16,t);

    if(flag) printf("-%ld",result);
    else printf("%ld",result);

    return 0;
}