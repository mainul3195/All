#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int prime[200005];
void sieve()
{
	int i,j;
	for(i=0; i<200005; i++)
		prime[i]=1;
	prime[0]=prime[1]=prime[2]=0;
	for(i=4; i<200005; i+=2)
		prime[i+1]=0;
	for(i=3; i<=448; i+=2)
		if(prime[i+1])
			for(j=i*i; j<=200000; j+=2*i)
				prime[j+1]=0;
	for(i=1; i<=200000; i++)
		prime[i]+=prime[i-1];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	while(1)
	{
		int a,b;
		cin >> a >> b;
		if(a==-1 && b==-1)
			return 0;
		if(a<0)
			a=0;
		if(b<0)
			b=0;
		cout << prime[b+1]-prime[a] << "\n";
	}
}