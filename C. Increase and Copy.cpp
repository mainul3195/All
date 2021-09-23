#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		if(n==1)
		{
			cout << "0\n";
			continue;
		}
		int sq=sqrt(n);
		int ans=((n-1)/sq + sq-1);
		// if(!(n%sq))
		// 	ans--;
		cout << ans << "\n";
	}

	return 0;
}