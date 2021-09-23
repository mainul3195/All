#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ckbit(x) (t[(x)/64] & 1<< (((x)%64)/2))
#define cngbit(x) (t[(x)/64] |= 1<< (((x)%64)/2))

int t[200000];
vector<long long>prime;
void sieve()
{
	for(int i=3; i<=3163; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=10000050; j+=2*i)
				cngbit(j);
	prime.push_back(2);
	for(int i=3; i<=10000050; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	return;
}
//int totient[10000007]
// void phi()
// {
// 	for(int i=1; i<=10000006; i++)
// 		totient[i]=i;
// 	for(int i=0; prime[i]<=10000003; i++)
// 	{
// 		totient[prime[i]]--;
// 		for(int j=prime[i]*2; j<=10000003; j+=prime[i])
// 			totient[j]=(long long)totient[j]*(prime[i]-1)/prime[i];
// 	}
// 	return;
// }
int totient(int n)
{
	int ans=n;
	for(int i=0; (long long)prime[i]*prime[i]<=n; i++)
		if(!(n%prime[i]))
		{
			while(!(n%prime[i]))
				n/=prime[i];
			ans = (long long)ans*(prime[i]-1)/prime[i];
		}
	if(n!=1)
		ans = (long long)ans*(n-1)/n;
	return ans;
}
int findprime(int n)
{
	int l=0, r=prime.size()-1;
	int mid;
	int ans=-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(prime[mid]<=n)
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	return ans+1;
}
int main()
{
	sieve();
	//phi();
	int n;
	int t;
	cin >> t;
	while(t-- && cin >> n)
	{
		int p=totient(n);
		int t=max(0, findprime(n)-p);
		if(t==2)
			cout << ((long long)p*p)%mod << "\n";
		else
			cout << p << "\n";
	}
	return 0;
}