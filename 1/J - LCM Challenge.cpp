#include<bits/stdc++.h>
using namespace std;
long long Lcm(long long a, long long b, long long c)
{
	long long lab = (a*b)/__gcd(a, b);
	return (lab*c)/__gcd(lab, c);
}
int main()
{
	int n;
	cin >> n;
	if(n<3)
		cout << n << "\n";
	else if(n==3)
		cout << "6\n";
	else
		cout <<max(Lcm(n, n-1, n-3), max(Lcm(n, n-1, n-2), Lcm(n-1, n-2, n-3))) << "\n";
	return 0;
}