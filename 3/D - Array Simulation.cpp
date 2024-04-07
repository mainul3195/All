#include<bits/stdc++.h>
using namespace std;
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	int tc=0;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		vector<int>a;
		for(int i=0; i<n; i++)
		{
			int j;
			cin >> j;
			a.push_back(j);
		}
		char c;
		for(int i=0; i<m; i++)
		{
			cin >> c;
			if(c=='S')
			{
				int d;
				cin >> d;
				for(int k=0; k<n; k++)
					a[k]+=d;
			}
			else if(c=='M')
			{
				int m;
				cin >> m;
				for(int k=0; k<n; k++)
					a[k]*=m;
			}
			else if(c=='D')
			{
				int d;
				cin >> d;
				for(int k=0; k<n; k++)
					a[k]/=d;
			}
			else if(c=='R')
				reverse(a.begin(), a.end());
			else if(c=='P')
			{
				int y, z;
				cin >> y >> z;
				int tp=a[y];
				a[y]=a[z];
				a[z]=tp;
			}
		}
		cout << "Case " << ++tc << ":\n";
		for(int i=0; i<n; i++)
			cout << a[i] << " \n"[i==n-1];
	}
	return 0;
}