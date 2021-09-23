#include<stdio.h>
#include<string.h>
int main()
{
    int count=0,  x, t,n, i;
    char string[100];

    scanf("%s", string);
    scanf("%d", &x);
    n=strlen(string);
    t=n/2;
    for(i=0; i<t; i++)

        if(string[i]!=string[n-i-1])
            count++;

    if(x>=count)
        puts("Semi-Palindrome");
    else
        puts("Not Semi-Palindrome");

    return 0;
}
