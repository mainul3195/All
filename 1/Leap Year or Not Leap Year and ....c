#include<stdio.h>
#include<string.h>
int divide(char yr[], int y)
{
    int length, temp, mod, k;
    length=strlen(yr);
    mod=yr[0]-'0';
    for(k=0;k<length-1;k++)
    {
        temp=yr[k]-'0';
        temp=mod*10+(yr[k+1]-'0');
        mod=temp%y;
    }
    if(mod==0)
        return 1;
    else return 0;
}
int main()
{
    int r,c;
    char year[10000];
    while((scanf("%s", year))==1)
    {


    if(r==1)
        printf("\n");
    r=c=0;

        if(divide(year,400)==1||(divide(year,100)==0&&divide(year,4)==1))
        {
            c=r=1;
            printf("This is leap year.\n");
        }
        if(divide(year,15)==1)
        {
            r=1;
            printf("This is huluculu festival year.\n");
        }
        if(c==1&&divide(year,55)==1){
                r=1;
            printf("This is bulukulu festival year.\n");
        }
        if(r!=1&&c!=1)
            printf("This is an ordinary year.\n\n");

    }
    return 0;
}
