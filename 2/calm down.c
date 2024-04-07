#include <stdio.h>
#include<math.h>
#define pi 2*acos(0.0)


int main()
{

    double R, r;
    int n, t, i=1;
    scanf("%d", &t);
    while(i<=t)
    {
        scanf("%lf %d", &R, &n);
        r =(R*sin((pi)/n))/(1+sin((pi)/n)) ;
        printf("Case %d: %.10f\n",i, r);
        i++;
    }
    return 0;
}
