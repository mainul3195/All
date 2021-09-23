#include<stdio.h>
#include<math.h>
int main()
{
    int t, array[100000], n,start,end, diff, difference[10000], finnum[10000],i,k,nw,j;
    scanf("%d", &t);

    for(i=0; i<t; i++)
    {
        scanf("%d", &n);
        for(j=0; j<n; j++)
            scanf("%d", &array[j]);
        k=0;
        diff=0;
        mainul:
            if(k+1<=n&&array[k]!=-1&&array[k+1]==-1)
                {
                    start=array[k];
                    k+=2;
                    mohsin:
                    if(array[k]!=-1)
                        end=array[k];
                    else
                    {
                        k++;
                        goto mohsin;
                    }
                    if(diff<abs(end-start))
                    {
                        diff=abs(end-start);
                        nw=(end+start)/2;
                    }

                    if(k+1>n)
                        goto khaled;
                    goto mainul;

                }
            else
                {
                    k++;
                    goto mainul;
                }

                khaled:

            if(diff%2!=0)
            difference[i]=(diff/2)+1;
            else
            difference[i]=diff/2;
            finnum[i]=nw;

    }

    for(i=0; i<t; i++)
        printf("%d %d\n",difference[i],finnum[i] );


    return 0;
}
