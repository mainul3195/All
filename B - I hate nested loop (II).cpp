#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,q,r;
long long i,l;
		cin >> n >> q;
		vector<long long> v;
		v.push_back(0);
		for(i=0; i<n; i++)
		{
			cin >> r;
			l=v[i]+r;
			v.push_back(l);
		}
		while(q--)
		{
			cin >> r >> l;
			if(l<r)
				l^=r^=l^=r;
			i=v[l+1]-v[r];
			cout << i << "\n";
		}
		if(t)cout << "\n";
	}
	return 0;
}