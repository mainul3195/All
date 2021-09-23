#include<stdio.h>
#include<string.h>
int main()
{
    int t, i=1;
    char a[10];
    scanf("%d", &t);
    while(i<=t)
    {
        int n;
        scanf("%d %s", &n, a);
        if(strcmp(a,"Bob")==0)
        {
            if(n%3==0)
                printf("Case %d: Alice\n", i);
            else
                printf("Case %d: Bob\n", i);
        }
        else
        {
            if(n%3==1)
                printf("Case %d: Bob\n", i);
            else
                printf("Case %d: Alice\n", i);
        }

        i++;
    }
}
