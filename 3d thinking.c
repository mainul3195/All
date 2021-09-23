#include<stdio.h>
int main()
{
    int i, t, x,y,z, x2, y2,z2;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        int n,maxx=0, vol, maxy=0, maxz=0, minx=10000, miny=10000, minz=10000;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d %d %d %d %d %d", &x,&y,&z, &x2, &y2,&z2);
            if(maxx<x)
                maxx=x;
            if(maxy<y)
                maxy=y;
            if(maxz<z)
                maxz=z;
            if(minx>x2)
                minx=x2;
            if(miny>y2)
                miny=y2;
            if(minz>z2)
                minz=z2;
        }
        if(minx<=maxx||miny<=maxy||minz<=maxz)
            vol=0;
        else
            vol=(minx-maxx)*(miny-maxy)*(minz-maxz);
        printf("Case %d: %d\n", i, vol);
    }
    return 0;
}
