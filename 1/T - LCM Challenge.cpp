#include<bits/stdc++.h>
long long gcd(long long a, long long b)
{
	if(!b)
		return a;
	return gcd(b, a%b);
}
long long lcm(long long a, long long b)
{
	return (a*b)/gcd(a, b);
}
using namespace std;
int main()
{
	long long n;
	cin >> n;
	if(n<3)
		cout << n;
	else if(n==3)
		cout << "6";
	else
		cout << max(max(lcm(lcm(n, n-1), n-2),lcm(lcm(n-1, n-2), n-3)),lcm(lcm(n-1, n), n-3));
	return 0;
}