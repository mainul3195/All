#include<bits/stdc++.h>
using namespace std;
long long mod(long long x, long long y, long long n)
{
	if(y==0)
		return 1;
	long long temp=mod(x, y/2, n);
	temp*=temp;
	if(y&1)
		temp*=x;
	temp%=n;
	return temp;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		long long x,y,n;
		cin >> x >> y >> n;
		cout << mod(x,y,n) << "\n";
	}
	return 0;
}