#include<stdio.h>
void execute()
{
    int i,k,j,n,c=0,f=0,x=1;
    char l;
    scanf("%d %d", &n, &j);
    for(i=0; i<n; i++)
    {
        k=0;
        scanf(" %c", &l);
        if(i==0 && l=='0')f=1;
        if(l=='1')x=0;
        while(l=='0' && ++i<n)
        {
            k++;
            scanf("%c", &l);
            if(l=='1') x=0;
        }
        if(l=='0' && i==n) k++;
        if(f && i==n && x)
            k=k;
        else if(f || i==n)
            k-=j;
        else
            k-=2*j;
        if(k<0)k=0;

        c+=((k+j)/(j+1));
    }
    printf("%d\n", c);
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        execute();
    return 0;
}