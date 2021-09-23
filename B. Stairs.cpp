#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		long long x;
		int c=0;
		cin >> x;
		long long tot=0;
		long long s=1;
		while(tot<=x)
		{
			tot+=(s*(s+1))/2;
			c++;
			s=2*s+1;
		}
		cout << c-1 << "\n";
	}
	return 0;
}