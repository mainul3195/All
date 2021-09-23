#include<stdio.h>
int main()
{
    int i, j, c=1, array[500]= {0}, n;
    scanf("%d", &n);
    if(n==1){
        printf("2\n");
        return 0;
    }

    for(i=3; i<=22; i+=2)
        if(!array[i])
            for(j=(i*i); j<=500; j+=(i+i))
                array[j]=1;

    for(i=3; i<=500; i+=2)
        if(!array[i])
            {
                c++;
                if(c==n)
                {
                    printf("%d\n", i);
                    return 0;

                }
            }
//    for(j=0; j<c; j++)
//        printf("%d%c", prime[j], ",\n"[j==c-1]);

}
