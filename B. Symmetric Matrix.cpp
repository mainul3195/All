#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		bool flag=0;
		int j,k,l;
		for(int i=0; i<n; i++)
		{
			cin >> l;
			cin >> j >> k;
			if(j==k)
			{
				//cout << j << " " << k << "\n";
				flag=1;
			}
			cin >> l;
		}
		if(flag && !(m&1))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}