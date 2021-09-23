#include<stdio.h>
long long fibo[100];
long long fibonacci(int n);
int main()
{
    int i, n;
    scanf("%d", &n);
    fibonacci(n);
    for(i=0; i<=n; i++)
        printf("Number of call by %d : %lld\n", i, fibo[i]);
    return 0;
}
long long fibonacci(int n)
{
    fibo[n]++;
    if(n<2)
        return n;
    return fibonacci(n-1)+fibonacci(n-2);
}
