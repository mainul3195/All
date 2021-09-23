#include<stdio.h>
#include<math.h>
#define pi (2*acos(0.0))
int main()
{
    int t, i=1, r1, r2, h, p;
    double vol;
    scanf("%d", &t);
    while(i<=t)
    {
        scanf("%d %d %d %d", &r1, &r2, &h, &p);
        if(r1==r2)
        vol=pi*r1*r1*p;
        else
            vol=(1/(double)3)*pi*(((r1*(r2*h+p*(r1-r2)))/(double)(r1*h))*((r1*(r2*h+p*(r1-r2)))/(double)(r1*h))*(p+((r2*h)/(double)(r1-r2)))-r2*r2*((r2*h)/(double)(r1-r2)));
        printf("Case %d: %.10lf\n", i, vol);
        i++;
    }
}
