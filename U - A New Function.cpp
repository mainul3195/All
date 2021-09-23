#include<bits/stdc++.h>
using namespace std;
long long pattase(int n)
{
	long long ans=0;
	for(long long i=2; i*i<=n; i++)
	{
		long long e=n/i;
		ans+=(e*(e+1))/2-(i*(i-1))/2+i*(n/i-i);
	}
	return ans;
}
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int t, i=0;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << "Case " << ++i << ": " << pattase(n) << "\n";
	}
	return 0;
}