#include <stdio.h>
int main()
{
    int t, i=1;
    scanf("%d", &t);
    while(i<=t)
    {
        int max=0, min=2000000000,j,n,x,y,z,mincount,maxcount;
                       scanf("%d", &n);
        char name[n][110];
        int volume[n];
            for(j=0; j<n; j++)
        {
            scanf("%s %d %d %d", name[j],&x, &y, &z);
            volume[j]=x*y*z;
            if(volume[j]<min)
            {
                min=volume[j];
                mincount=j;
            }
            if(volume[j]>max)
            {
                max=volume[j];
                maxcount=j;
            }


        }

        if(maxcount!=mincount)
            printf("Case %d: %s took chocolate from %s\n", i, name[maxcount], name[mincount]);
        else
            printf("Case %d: no thief\n", i);
        i++;
    }
    return 0;
}
