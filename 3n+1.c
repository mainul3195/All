#include<stdio.h>
#include<math.h>
int main()
{
    int t, n, d, array[100000],i,j,c, max;
    scanf("%d", &t);
    for(i=0; i<t ;i++)
    {
        max=0;
        scanf("%d %d", &n, &d);
        for(j=0; j<n; j++)
        {
            scanf("%d", &array[j]);
        }
        for(j=0; j<n; j++)
        {
            if(d==array[j])
                {
                    c=1;
                    goto mainul;

                }
        }
        for(j=0; j<n; j++)
        {
            if(max<array[j])
                max=array[j];
        }

        c=ceil((float)d/max);
        if(c==1)
            c++;

        mainul:
           printf("%d\n", c);

    }


    return 0;

}
