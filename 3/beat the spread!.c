#include<stdio.h>
#include<math.h>
int main()
{
    int d,n,s,t,x,y;
scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d",&s, &d);
        if(s<d)
            printf("impossible\n");
        else
        {
            y=(s-d)/2;
            x=d+y;
            if(x+y==s&&abs(x-y)==d)
            printf("%d %d\n", x,y );
            else
                printf("impossible\n");

        }

    }
    return 0;
}
