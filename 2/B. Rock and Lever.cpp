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
		for(int i=0; i<n; i++)
		{
			int j,count=0;
			cin >> j;
			while(j)
			{
				count++;
				j>>=1;
			}
			v[i]=count;
		}
		long long ans=0;
		sort(v.begin(), v.end());
		// for(int i=0; i<n; i++)
		// 	cout << v[i] << " \n"[i==n-1];
		for(int i=1; i<n; i++)
		{
			long long count=1;
			while(i<n && v[i]==v[i-1])
				count++,i++;
			ans+=((count*(count-1))/2);
		}
		cout << ans << "\n";
	}
	return 0;
}