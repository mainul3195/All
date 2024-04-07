#include<stdio.h>
int main()
{
    int array[2000],test[2000], t, n,i,j;

    scanf("%d", &t);


    for(j=0; j<t; j++)
    {


        scanf("%d", &n);
        for(i=0; i<n; i++)
            scanf("%d", &array[i]);


        if(array[0]%2==0)
        {

            for(i=1; i<n; i++)
            {
                if(array[i]%2!=0)
                    goto mainul;

            }
            test[j]=0;
            continue;
        }

        else
        {
            for(i=1; i<n; i++)
            {
                if(array[i]%2==0)
                    goto mainul;

            }
            if(n%2==0)
            {
                test[j]==0;
                continue;

            }
            else
                goto mainul;


        }
        mainul:
            test[j]=1;




    }
    for(i=0; i<t; i++)
    {
        if(test[i]==0)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;

}
