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
int phi(int n)
{
	int ans=n;
	for(int i=0; prime[i]*prime[i] <=n; i++)
	{
		if(!(n%prime[i]))
		{
			while(!(n%prime[i]))
				n/=prime[i];
			ans = (long long)ans*(prime[i]-1)/prime[i];
		}
	}
	if(n!=1)
		ans = (long long)ans*(n-1)/n;
	return ans;
}
int main()
{
	sieve();
	int n;
	int t;
	//cin >> t;
	while(cin >> n && n)
		cout << n-phi(n)-1 << "\n";
	return 0;
}