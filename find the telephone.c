#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    int length, i;
    while((scanf("%s", s))!=EOF)
    {
        length=strlen(s);
        for(i=0; i<length; i++)
        {
            if(s[i]>='A'&&s[i]<='C')
                s[i]='2';
            else if(s[i]>='D'&&s[i]<='F')
                s[i]='3';
            else if(s[i]>='G'&&s[i]<='I')
                s[i]='4';
            else if(s[i]>='J'&&s[i]<='L')
                s[i]='5';
            else if(s[i]>='M'&&s[i]<='O')
                s[i]='6';
            else if(s[i]>='P'&&s[i]<='S')
                s[i]='7';
            else if(s[i]>='T'&&s[i]<='V')
                s[i]='8';
            else if(s[i]>='W'&&s[i]<='Z')
                s[i]='9';
        }
        puts(s);
    }
}
