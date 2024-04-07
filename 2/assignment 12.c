
#include<stdio.h>

void fact(int m)
{
    int mul[200], temp[200], x,i,j,k,l,r,n,count, tmp;
    for( i=0; i<200; i++)
    {
        mul[i]=20;
    }
    mul[0]=1;
    for(x=m; m>1; m--)
    {
        n=m;
        for( i=0; i<200; i++)
            temp[i]=20;
        k=0;
        for(r=n%10; r!=0||n!=0; r=n%10)
        {

            int carry=0;
            n/=10;
            i=0;
            j=k++;
            do
            {
                tmp=(mul[i]%10)*r+carry+temp[j]%10;
                temp[j]=(tmp)%10;
                carry=tmp/10;
                i++;
                j++;
            }
            while(carry!=0||mul[i]!=20);
        }
        for(i=0; temp[i]!=20; i++)
            mul[i]=temp[i];
    }
    for(i=0; mul[i]!=20; i++);
    printf("The factorial of %d is ", x);
    for(i--; i>=0; i--)
        printf("%d", mul[i]);
    puts("");
}


int prm(int n)
{

    int c=3, i, j, prime[400]= {0};
    if(n==1)
    {
        printf("The 1st prime number is 2\n");
        return 0;
    }
    else if(n==2)
    {
        printf("The 2nd prime number is 3\n");
        return 0;
    }
    else if(n==3)
    {
        printf("The 3rd prime number is 5\n");
        return 0;
    }

    for(i=3; i<=20; i+=2)
        if(!prime[i])
            for(j=(i*i); j<=400; j+=(i+i))
                prime[j]=1;

    for(j=7; j<=400; j+=2)
        if(!prime[j])
        {
            c++;
            if(c==n)
            {
                printf("The %dth prime number is %d\n",n, j);
                return 0;
            }
        }
}
int fibonacci(int n)
{
    int x=n;
    if(n==1)
    {
        printf("The 1st fibonacci number is 1\n");
        return 0;
    }
    else if(n==2)
    {
        printf("The 2nd fibonacci number is 1\n");
        return 0;
    }
    else if(n==3)
    {
        printf("The 3rd fibonacci number is 2\n");
        return 0;
    }
    long long a,b,c;
    a=0;
    b=1;
    while(n--)
    {
        c=a+b;
        a=b;
        b=c;
    }
    printf("The %dth fibonacci number is %lld\n",x, a);
    return 0;

}


int lucas(int n)
{
    int x=n;
    if(n==1)
    {
        printf("The 1st lucas number is 1\n");
        return 0;
    }
    else if(n==2)
    {
        printf("The 2nd lucas number is 3\n");
        return 0;
    }
    else if(n==3)
    {
        printf("The 3rd lucas number is 4\n");
        return 0;
    }
    long long a,b,c;
    a=2;
    b=1;
    while(n--)
    {
        c=a+b;
        a=b;
        b=c;
    }
    printf("The %dth lucas number is %lld\n",x, a);
    return 0;
}


int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        prm(n);
        lucas(n);
        fibonacci(n);
        fact(n);
    }
    return 0;
}

