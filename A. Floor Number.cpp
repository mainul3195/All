#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,x;
		cin >> n >> x;
		cout << 1+(max(n-2, 0)+x-1)/x << "\n";
	}
	return 0;
}