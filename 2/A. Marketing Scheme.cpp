#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int l,r;
		cin >> l >> r;
		if((double)l>=(double)(r+1)/2)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}