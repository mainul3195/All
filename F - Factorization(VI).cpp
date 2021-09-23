#include<bits/stdc++.h>
using namespace std;
int findmx(int n)
{
	int c=0,mx=0;
	while(!(n&1))
	{
		c++;
		n>>=1;
	}
	mx=max(mx,c);
	for(int i=3; i*i<=n; i+=2)
	{
		c=0;
		while(!(n%i))
		{
			c++;
			n/=i;
		}
		mx=max(c,mx);
	}
	if(n!=1)
		mx=max(mx,1);
	return mx;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << findmx(n) << "\n";
	}
	return 0;
}