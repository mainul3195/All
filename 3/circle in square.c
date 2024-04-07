#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)
int main()
{
    int t, i=1;
    double r;
    scanf("%d", &t);
    while(i<=t)
    {

        scanf("%lf", &r);
        printf("Case %d: %.2lf\n", i, (r*r*(4-pi)));
            i++;
    }
    return 0;
}

