#include<stdio.h>
#define pi 3.141592654
int main()
{
    int t,i;
    double r,v,r1,r2,h,p;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
		scanf("%lf %lf %lf %lf",&r1,&r2,&h,&p);
		r=r2+((r1-r2)*p)/h;
		v=(pi*p*(r2*r2+r2*r+r*r))/3.0;
		printf("Case %d: %.9lf\n",i,v);
    }
    return 0;
}
