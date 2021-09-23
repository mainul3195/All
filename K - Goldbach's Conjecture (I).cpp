#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2)
int t[15700];
void sieve()
{
	int i,j;
	cngbit(1);
	for(i=3; i*i<1001000; i+=2)
		if(!ckbit(i))
			for(j=i*i; j<=1001000; j+=2*i)
				cngbit(j);
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
		int i=n;
		if(!(i%2))
			i--;
		for(; i>=1; i-=2)
			if(!ckbit(i) && !ckbit(n-i))
			{
				cout << n << " = " << n-i << " + " << i << "\n";
				break;
			}
	}
}