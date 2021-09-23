#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/32] & 1 << (x)%32)
#define cngbit(x) (t[(x)/32] |= 1 << (x)%32)
int t[40000];
void sieve()
{
	cngbit(0);
	cngbit(1);
	for(int i=4; i<=1000000; i+=2)
		cngbit(i);
	for(int i=3; i<=1000; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=1000000; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	return ;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	int n;
	while(cin >> n)
	{
		if(!n)
			return 0;
		bool flag=1;
		for(int i=n-1; i>=n/2; i--)
			if(!ckbit(i) && !ckbit(n-i))
			{
				cout << n << ":\n" << n-i << "+" << i << "\n";
				flag=0;
				break;
			}
		if(flag)
			cout << n << ":\n" << "NO WAY!\n";
	}
}