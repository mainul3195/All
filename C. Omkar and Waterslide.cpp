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
		int i,j;
		vector<int>v;
		for(i=0; i<n ;i++)
		{
			cin >> j;
			v.push_back(j);
		}
		int mx=v[0];
		long long fans=0,ans=0;
		for(i=1; i<n ;i++)
		{
			if(v[i]<mx && v[i]<v[i-1])
				ans+=v[i-1]-v[i];
			else if(v[i]>=mx)
			{
				fans+=ans;
				ans=0;
				mx=v[i];
			}
		}
		if(ans) fans+=ans;
		cout << fans << "\n";
	}
	return 0;
}