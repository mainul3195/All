#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, k;
		cin >> a >> b >> k;
		cout << (long long)(a-b)*(k/2) + a*(k%2) << "\n";
	}
	return 0;
}