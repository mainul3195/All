#include<stdio.h>
#include<string.h>
int main()
{
    int count=0, t,n, i;
    char string[100];

    scanf("%s", string);

    n=strlen(string);
    t=n/2;
    for(i=0; i<t; i++)
    {
        if(string[i]!=string[n-i-1])
            count++;
    }
   printf("%d", count);

    return 0;
}

