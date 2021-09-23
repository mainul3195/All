#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/32] & 1 << ((x)%32))
#define cngbit(x) (t[(x)/32] |= 1 << ((x)%32))
int t[40];
vector<int> prime;
void sieve()
{
	prime.push_back(2);
	for(int i=4; i<=1000; i+=2)
		cngbit(i);
	for(int i=3; i<=31; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=1000; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(int i=3; i<=1000; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	return;
}
int power(int a, int b)
{
	int ans=1;
	while(b--)
		ans*=a;
	return ans;
}
int sum(int n)
{
	int ans=1,i;
	for(i=0; prime[i]*prime[i]<=n; i++)
	{
		int count=0;
		while(!(n%prime[i]))
		{
			count++;
			n/=prime[i];
		}
		if(count)
			ans*=((power(prime[i], count+1)-1)/(prime[i]-1));
	}
	if(n!=1)
		ans*=((power(n, 2)-1)/(n-1));
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	sieve();
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << sum(n)-n << "\n";
	}
	return 0;
}