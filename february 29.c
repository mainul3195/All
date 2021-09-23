#include<string.h>
#include<stdio.h>
int main()
{
    int t, i=1, n,m1,m2,d1,temp,d2,y1,y2,j,count;
    char a[15],b[15];
    scanf("%d", &t);
    while(i<=t)
    {
        count=0;
        scanf("%s %d, %d", a, &d1, &y1);
        scanf("%s %d, %d", b, &d2, &y2);

        if(strcmp(a,"January")==0)
            m1=1;
        else if(strcmp(a,"February")==0)
            m1=2;
        else if(strcmp(a,"March")==0)
            m1=3;
        else if(strcmp(a,"April")==0)
            m1=4;
        else if(strcmp(a,"May")==0)
            m1=5;
        else if(strcmp(a,"June")==0)
            m1=6;
        else if(strcmp(a,"July")==0)
            m1=7;
        else if(strcmp(a,"August")==0)
            m1=8;
        else if(strcmp(a,"September")==0)
            m1=9;
        else if(strcmp(a,"October")==0)
            m1=10;
        else if(strcmp(a,"November")==0)
            m1=11;
        else if(strcmp(a,"December")==0)
            m1=12;




        if(strcmp(b,"January")==0)
            m2=1;
        else if(strcmp(b,"February")==0)
            m2=2;
        else if(strcmp(b,"March")==0)
            m2=3;
        else if(strcmp(b,"April")==0)
            m2=4;
        else if(strcmp(b,"May")==0)
            m2=5;
        else if(strcmp(b,"June")==0)
            m2=6;
        else if(strcmp(b,"July")==0)
            m2=7;
        else if(strcmp(b,"August")==0)
            m2=8;
        else if(strcmp(b,"September")==0)
            m2=9;
        else if(strcmp(b,"October")==0)
            m2=10;
        else if(strcmp(b,"November")==0)
            m2=11;
        else if(strcmp(b,"December")==0)
            m2=12;

        if(m1>2)
            y1++;
        if(m2<2||(m2==2&&d2<29))
            y2--;


            count=(y2/4)-(y2/100)+(y2/400)-((y1-1)/4)+((y1-1)/100)-((y1-1)/400);
        printf("Case %d: %d\n", i, count);
        i++;
    }
    return 0;
}
