#include<stdio.h>
#include<string.h>
int main()
{
    char a[100001];
    int count[26], l, i, mul=1;
    gets(a);
    l=strlen(a);
    for(i=0; i<26; i++)
        count[i]=0;
    for(i=0; i<l; i++)
    {
        if(a[i]=='a')
            count[0]++;
        else if(a[i]=='b')
            count[1]++;
        else if(a[i]=='c')
            count[2]++;
        else if(a[i]=='d')
            count[3]++;
        else if(a[i]=='e')
            count[4]++;
        else if(a[i]=='f')
            count[5]++;
        else if(a[i]=='g')
            count[6]++;
        else if(a[i]=='h')
            count[7]++;
        else if(a[i]=='i')
            count[8]++;
        else if(a[i]=='j')
            count[9]++;
        else if(a[i]=='k')
            count[10]++;
        else if(a[i]=='l')
            count[11]++;
        else if(a[i]=='m')
            count[12]++;
        else if(a[i]=='n')
            count[13]++;
        else if(a[i]=='o')
            count[14]++;
        else if(a[i]=='p')
            count[15]++;
        else if(a[i]=='q')
            count[16]++;
        else if(a[i]=='r')
            count[17]++;
        else if(a[i]=='s')
            count[18]++;
        else if(a[i]=='t')
            count[19]++;
        else if(a[i]=='u')
            count[20]++;
        else if(a[i]=='v')
            count[21]++;
        else if(a[i]=='w')
            count[22]++;
        else if(a[i]=='x')
            count[23]++;
        else if(a[i]=='y')
            count[24]++;
        else if(a[i]=='z')
            count[25]++;
    }
     for(i=0; i<26; i++)
     {
         if(count[i]==0)
            continue;
         mul*=count[i];
     }

        printf("%d", mul);
    return 0;
}
