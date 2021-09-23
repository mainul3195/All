#include<stdio.h>
#include<math.h>

long long prime(long long n);
long long factorial(long long n);
long long fibonacci(long long n);
long long lucas(long long n);

long long main()
{
    long long n;
    while(scanf("%lld", &n)!=EOF)
    {
        printf("The no. %lld \n\tPrime number is %lld\n", n,prime(n));
        printf("\tLucas number is %lld\n", lucas(n));
        printf("\tFibonacci number is %lld\n", fibonacci(n));
        printf("The factorial of %lld is %lld\n", n,factorial(n));
    }
    return 0;
}
long long factorial(long long n)
{
    long long i,fact=1;
    for(i=n; i>0; i--)
        fact*=i;
    return fact;
}
long long fibonacci(long long n)
{
    long long a,b,c,count=0;
    a=0;
    b=1;
    while(1)
    {
        if(count==n)
            return a;
        count++;
        c=a+b;
        a=b;
        b=c;
    }

}
long long lucas(long long n)
{
    long long a,b,c,count=0;
    a=2;
    b=1;
    while(1)
    {
        if(count==n)
            return a;
        count++;
        c=a+b;
        a=b;
        b=c;
    }

}
long long prime(long long n)
{
    long long c=0,i,array[400]= {0},j, sievelim;
    sievelim=sqrt(400);
    if(n==0)
        return 0;
    if(n==1)
        return 2;
    for(i=3; i<=sievelim; i+=2)
    {
        for(j=i*i; j<400; j+=i+i)
        {
            array[j]=1;
        }

    }
    c++;

    for(i=3; i<400; i+=2)
    {
        if(array[i]==0)
        {
            c++;
            if(c==n)
                return i;
        }
    }

}
