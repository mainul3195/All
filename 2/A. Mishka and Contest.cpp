#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	int ok=1;
	vector<int> v(n);
	for(int i=0; i<n; i++)
	{
		cin >> v[i];
		if(v[i]>k)
			ok=0;
	}
	if(ok)
		cout << n;
	else
	{
		int ans=0;
		for(int i=0; i<n; i++)
		{
			if(v[i]>k)
				break;
			ans++;
		}
		for(int i=n-1; i>0; i--)
		{
			if(v[i]>k)
				break;
			ans++;
		}
		cout << ans;
	}
	return 0;
}