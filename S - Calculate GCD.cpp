#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if(!b)
		return a;
	return gcd(b, a%b);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int a;
		string b;
		cin >> a >> b;
		if(!a)
		{
			cout << b << "\n";
			continue;
		}
		int i, l=b.size(), remainder=0;
		for(i=-1; i<l; )
		{
			if(remainder<a && ++i<l)
				remainder = remainder*10 + b[i]-48;
			else
				remainder%=a;
		}
		cout << gcd(a,remainder) << "\n";
	}
	return 0;
}