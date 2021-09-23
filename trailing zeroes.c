#include<stdio.h>

int x_in_nfact(int num, int x)
{
    int i=0, j=x;
    while(j<=num)
    {
        i+=num/j;
        j*=x;
    }
    return i;
}
int x_in_n(int num, int x)
{
    int i=0;
    while(num%x==0)
    {
        i++;
        num/=x;
    }
    return i;
}
int main()
{
    int i, t, n, r, p, q, no2, no5, temp;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%d %d %d %d", &n, &r, &p, &q);
        no2=x_in_nfact(n, 2)-x_in_nfact(r, 2)-x_in_nfact(n-r, 2)+q*x_in_n(p,2);
        no5=x_in_nfact(n, 5)-x_in_nfact(r, 5)-x_in_nfact(n-r, 5)+q*x_in_n(p,5);
        if(no2<no5)
        {
            temp=no2;
            no2=no5;
            no5=temp;
        }
        printf("Case %d: %d\n", i, no5);
    }
}
