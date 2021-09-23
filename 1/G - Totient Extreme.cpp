#include<iostream>
#include<vector>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1<< (((x)%64)/2))
#define cngbit(x) (t[(x)/64] |= 1<< (((x)%64)/2))

int t[20000];
vector<long long>prime;
void sieve()
{
	for(int i=3; i<=1000; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=1000000; j+=2*i)
				cngbit(j);
	prime.push_back(2);
	for(int i=3; i<=1000000; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	return;
}
// int phi(int n)
// {
// 	int ans=n;
// 	for(int i=0; prime[i]*prime[i] <=n; i++)
// 	{
// 		if(!(n%prime[i]))
// 		{
// 			while(!(n%prime[i]))
// 				n/=prime[i];
// 			ans = (long long)ans*(prime[i]-1)/prime[i];
// 		}
// 	}
// 	if(n!=1)
// 		ans = (long long)ans*(n-1)/n;
// 	return ans;
// }
int totient[10005];
long long sum[10004];
void phi()
{
	for(int i=1; i<=10004; i++)
		totient[i]=i;
	for(int i=0; prime[i]<=10003; i++)
	{
		totient[prime[i]]--;
		for(int j=prime[i]*2; j<=10003; j+=prime[i])
			totient[j]=(long long)totient[j]*(prime[i]-1)/prime[i];
	}
	for(int i=1; i<=10003; i++)
		sum[i]=totient[i]+sum[i-1];
	return;
}
long long calc(int n)
{
	long long h=0;
	for(int i=1; i<=n; i++)
		h+= totient[i]*sum[n];
	return h;
}
int main()
{
	sieve();
	phi();
	int n;
	int t;
	cin >> t;
	while( t-- && cin >> n)
		cout << calc(n) << "\n";
	return 0;
}