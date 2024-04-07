#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		vector<int>v(n);
		for(int i=0; i<n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		int count=0;
		for(int i=1; i<n; i++)
			count+=((max(k-v[i], 0))/v[0]);
		cout << count << "\n";
	}
	return 0;
}