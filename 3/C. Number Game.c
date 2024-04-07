#include<stdio.h>
#include<math.h>
int a[1500],prime[4000];

void seive(int);
void change(int j);
void execute();

int main()
{
    int t;
    scanf("%d", &t);
    seive(33000);
    while(t--)
        execute();
    return 0;
}

void execute()
{
    int n,prime_d[20]={0},i,j=-1,l;
    scanf("%d", &n);
   // printf("%d-", n);
    if(n==1) printf("FastestFinger\n");
    else if(n%2) printf("Ashishgup\n");
    else
    {
        l=sqrt(n);
        //printf("%d ", n);
        for(i=0; prime[i]<=l && n>1; i++)
        {
            if(!(n%prime[i]))
            {
                j++;
                while(!(n%prime[i]))
                {
                    n/=prime[i];
                    prime_d[j]++;
                  //  printf("%d ", prime_d[j]);
                }
            }
        }
        if(n!=1)
            prime_d[++j]++;
        l=prime_d[0];
        j=0;
        for(i=1; prime_d[i]; i++)
            j+=prime_d[i];
      //  printf("%d %d\n", l, j);
        if((l==1 && (!j || j>1)) || (l>1 && j))
            printf("Ashishgup\n");
        else printf("FastestFinger\n");
    }
}

void change(int j)
{
    int k,l;
    k=(j/32);
    l=j%32;
    a[k] |= (1<<l);
}

void seive(int n)
{
    int i,j,k,l,c=0;
    for(i=3; i<=n; i+=2)
    {
        k=i/32;
        l=i%32;
        if(!(a[k] & 1<<l))
        {
            for(j=i*i; j<=n; j+=i*2)
                change(j);
        }
    }
    prime[c++]=2;
    for(i=3; i<=n; i+=2)
    { 
        k=i/32;
        l=i%32;
        if(!(a[k] & 1<<l))
            prime[c++]=i;
    }
//    for(i=0; i<c; i++)
//        printf("%d%c", prime[i], ",\n"[i==c-1]);

   //printf("%d, %d",prime[c-1], c);
}

