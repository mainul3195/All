#include <stdio.h>
int main()
{
    int n, p, q, t, i=1,t1, t2, maxc,minc,j,max, min, count, sum, x[110], y[110], z[110];
    char name[110][25];
    scanf("%d", &t);
    while(i<=t)
    {
        scanf("%d", &n);
        for(j=0;j<n; j++)
        scanf("%s %d %d %d", name[j],&x[j], &y[j], &z[j]);
      max=maxc=minc=0;
                  min=x[0]*y[0]*z[0];

        for(j=0; j<n ;j++)
        {
            t1=x[j]*y[j]*z[j];
            if(t1!=max&&t1!=min)
            {
                if(t1>max){
                max=t1;
                maxc=j;}
                if(t1<min){
                        minc=j;
                    min=t1;}

            }
        }
        if(maxc!=minc)
            printf("Case %d: %s took chocolate from %s\n", i, name[maxc], name[minc]);
        else
            printf("Case %d: no thief\n", i);
        i++;
    }
    return 0;
}
