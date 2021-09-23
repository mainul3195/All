#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--)
	{
		long long n, a, b;
		cin >> n >> a >> b;
		if(2*a<b)
			b=2*a;
		cout << (n/2)*b + (n%2)*a << "\n";
	}
	return 0;
}