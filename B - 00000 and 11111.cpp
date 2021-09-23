#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	int tc=0;
	while(cin >> s)
	{
		cout << "Case " << ++tc << ":\n";
		int l=s.size();
		vector<int>v(l+1, 0);
		for(int i=1; i<=l; i++)
			v[i]=v[i-1]+s[i-1]-48;
		int q;
		cin >> q;
		while(q--)
		{
			int l,r;
			cin >> l >> r;
			if(l>r)
				l^=r^=l^=r;
			if(v[r+1]-v[l]==r-l+1 || !(v[r+1]-v[l]))
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
	return 0;
}