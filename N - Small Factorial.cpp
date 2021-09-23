#include<bits/stdc++.h>
using namespace std;
long long fact(long long n)
{
	if(n<2)
		return 1;
	return n*fact(n-1);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		long long n;
		cin >> n;
		cout << fact(n) << "\n";
	}
	return 0;
}