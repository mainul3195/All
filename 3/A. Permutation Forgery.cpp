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
		vector<int> v;
		int i,j;
		for(i=0; i<n; i++)
		{
			cin >> j;
			v.push_back(j);
		}
		reverse(v.begin(), v.end());
		for(i=0; i<n; i++)
			cout << v[i] << " \n"[i==n-1];
	}
	return 0;
}