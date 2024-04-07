#include<stdio.h>


int main()
{
    int i=0,t;

    scanf("%d", &t);
    unsigned int a,c,b=0,s[t];
    while(i<t)
    {
        scanf("%u", &s[i]);
        i++;
    }
    for(i=0; i<t; i++)
    {

        c=s[i];
        while( c>=10 )
        {
            a=c%10;
            b+=(c-a);
            c/=10;
            c+=a;
        }
        b+=c;
        printf("%u\n", b);
        b=0;

    }
    return 0;
}
