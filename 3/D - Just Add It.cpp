#include<bits/stdc++.h>
using namespace std;
long long mod(long long a, long long b, long long n)
{
	if(!b)
		return 1;
	long long temp=mod(a, b/2, n);
	temp*=temp;
	temp%=n;
	if(b&1)
		temp*=a;
	return temp%n;
}
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	long long n,k, M=10000007;
	while(cin >> n >> k)
	{
		if(!n && !k)
			return 0;
		cout << (2*mod(n-1, k, M) + mod(n, k, M) + 2*mod(n-1, n-1, M)+ mod(n, n, M))%M << "\n";
	}
	return 0;
}