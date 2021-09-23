#include<stdio.h>
#include<math.h>
int main()
{
    int t,i=1,o1, o2, a1, a2, b1, b2;
    double oa,ob,ab,arcdis, angle;
    scanf("%d", &t);
    while(i<=t)
    {
        scanf("%d %d %d %d %d %d",&o1, &o2, &a1, &a2, &b1, &b2);
        ab=sqrt(((b1-a1)*(b1-a1))+((b2-a2)*(b2-a2)));
        oa=sqrt(((o1-a1)*(o1-a1))+((o2-a2)*(o2-a2)));
        ob=sqrt(((o1-b1)*(o1-b1))+((o2-b2)*(o2-b2)));

        angle=acos(((oa*oa)+(ob*ob)-(ab*ab))/(2.0*oa*ob));
        arcdis=oa*angle;



        printf("Case %d: %lf\n", i,arcdis);


        i++;
    }

    return 0;
}

