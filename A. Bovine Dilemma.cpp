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
		vector<int> v(n);
		for(int i=0; i<n ;i++)
			cin >> v[i];
		map<int, int> mp;
		int count=0;
		for(int i=0; i<n-1; i++)
			for(int j=i+1; j<n; j++)
			{
				if(!mp[v[j]-v[i]])
				{
					count++;
					mp[v[j]-v[i]]++;
				}
			}
		cout << count << "\n";
	}
	return 0;
}