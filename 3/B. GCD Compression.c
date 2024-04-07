#include<stdio.h>
void execute()
{
    int f=1,i,j=0,k=0,so,se,x,n,even[2004], odd[2004];
    scanf("%d", &n);
    for(i=1; i<=2*n; i++)
    {
        scanf("%d", &x);
        if(x%2) odd[j++]=i;
        else even[k++]=i;
    }
    if(j%2)
    {
        so=1,se=1;
    }
    else
    {
        if(j>=2)
            so=2,se=0;
        else
            se=2,so=0;
    }
    while(se<k)
    {
        f=(++f)%2;
        printf("%d%c", even[se++], " \n"[f]);
    }
    while(so<j)
    {
        f=(++f)%2;
        printf("%d%c", odd[so++], " \n"[f]);
    }
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