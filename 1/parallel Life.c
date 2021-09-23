#include<stdio.h>
#include<math.h>
int main()
{
    int a1, a2, b1, b2, c1, c2, d1, d2, i=1, s, area, t;
    scanf("%d", &t);
    while(i<=t)
    {
        scanf("%d %d %d %d %d %d", &a1, &a2, &b1, &b2, &c1, &c2);
        d1=a1+c1-b1;
        d2=a2+c2-b2;
        area=.5*(a1*b2+b1*c2+c1*d2+d1*a2-a2*b1-b2*c1-c2*d1-d2*a1);
        area=abs(area);
        printf("Case %d: %d %d %d\n", i, d1, d2, area);
        i++;
    }

    return 0;
}
