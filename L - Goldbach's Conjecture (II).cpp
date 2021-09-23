#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/32] & 1 << (x)%32)
#define cngbit(x) (t[(x)/32] |= 1 << (x)%32)
int t[3500000];
void sieve()
{
	int i,j;
	cngbit(0);
	cngbit(1);
	for(i=4; i<=100000000; i+=2)
		cngbit(i);
	for(i=3; i<=10000; i+=2)
		if(!ckbit(i))
			for(j=i*i; j<=100000000; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	int n;
	while(cin >> n)
	{
		bool flag=1;
		if(n%2 && n!=1 && !ckbit(n-2))
			cout << n << " is the sum of 2 and " << n-2 << ".\n";
		else if(!(n%2))
		{
			for(int i=n/2; i>=2; i--)
				if(!ckbit(i) && !ckbit(n-i) && i!=n-i)
				{
					flag=0;
					cout << n << " is the sum of " << i << " and " << n-i << ".\n";
					break;
				}
			if(flag)
				cout << n << " is not the sum of two primes!\n";
		}
		else
			cout << n << " is not the sum of two primes!\n";
	}
	return 0;
}