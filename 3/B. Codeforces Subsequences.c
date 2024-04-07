#include<stdio.h>
int main()
{
    long long k,i,j,tot,a[10],c;
    char str[]="codeforces";
    scanf("%lld", &k);
    c=tot=1;
    while(tot<=k)
    {
        c++;
        tot=1;
        for(i=0; i<10; i++)
            tot*=c;
    }
    c--;
    for(i=0; i<10; i++)
        a[i]=c;
    for(i=0; i<10; i++)
    {
        tot=1;
        for(j=0; j<10; j++)
            tot*=a[j];
        if(tot>=k)
            break;
        a[i]++;
    }
    for(i=0; i<10; i++)
    {
        tot=a[i];
        for(j=0; j<tot; j++)
            printf("%c", str[i]);
    }
    puts("");
    return 0;
}
