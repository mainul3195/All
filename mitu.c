#include<stdio.h>
#include<math.h>
#define sz 100000000
int siv[sz], prime[sz], count;

int main()
{
    long long int i,j,n;
    scanf("%lld", &n);
    long long int power, limit = sqrt(n)+1;
    for(i=3;i<=limit;i+=2){
        if(siv[i]==0){
            for(j=i*i;j<=n;j+=i+i){
                siv[j]=1;
            }
        }
    }
    prime[count++] = 2;
    for(i=3;i<=n;i+=2){
        if(siv[i]==0){
            prime[count++]=i;
        }
    }
    for(i=0;i<count;i++){
        if(n % prime[i] == 0){
            power = 1;
            for(j = n/prime[i];j % prime[i] == 0; j = j/prime[i]){
                power++;
            }
    printf("%d^%d ", prime[i], power);
        }
    }
    return 0;
}
