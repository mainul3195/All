#include<bits/stdc++.h>
using namespace std;
long long lcm(long long a, long long b)
{
	long long ans=1;
	long long lim=max(sqrt(a), sqrt(b)) +1;

	while(!(a%2) || !(b%2))
	{
		if(!(a%2))
			a/=2;
		if(!(b%2))
			b/=2;
		ans*=2;
	}
	for(long long i=3; i<=lim; i+=2)
	{
		while(!(a%i) || !(b%i))
		{
			if(!(a%i))
				a/=i;
			if(!(b%i))
				b/=i;
			ans*=i;
		}
	}
	if(a==b)
		ans*=a;
	else
		ans*=a*b;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		long long n, a, b, k;
		cin >> n >> a >> b >> k;
		if(n/a + n/b - 2*(n/lcm(a, b)) >=k)
			cout << "Win\n";
		else
			cout << "Lose\n";
	}
	return 0;
}