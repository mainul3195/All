#include<bits/stdc++.h>
using namespace std;
int Log2(long long n)
{
	if(n==1)
		return 0;
	return 1+Log2(n/2);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n;
	cin >> n;
	cout << Log2(n);
	return 0;
}