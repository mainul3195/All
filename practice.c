/*
#include<stdio.h>
#include<string.h>
void execute()
{
    int i,l;
    char c[102];
    scanf("%s", c);
    l=strlen(c);
    printf("%c", c[0]);
    for(i=1; i<l; i+=2)
        printf("%c", c[i]);
    puts("");
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        execute();
    return 0;
}#include<stdio.h>
#include<string.h>
int main()
{
    char s1[100], s2[100];
    scanf("%s %s", s1, s2);
    strcat(s2,s1);
    printf("%s", s2);
    return 0;
}*/

#include <stdio.h>
struct {
    unsigned c[5] : 1;
}v;
int main()
{
   char c,s[35];
   int i=sizeof(v);
   printf("%d", i);
   return 0;
}