#include<stdio.h>
void execute()
{
    int i,l,n,o=0,e=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &l);
        if(i%2)
        {
            if(!(l%2))
                o++;
        }
        else
            if(l%2)
                e++;
    }
    if(o!=e)
        printf("-1\n");
    else
        printf("%d\n", o);
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