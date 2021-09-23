#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int l, b;
		cin >> l >> b;
		cout << __gcd(l, b) << "\n";
	}
	return 0;
}