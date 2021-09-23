#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q; 
	map<string, int> mp;
	while(q--)
	{
		int a;
		string s;
		cin >> a >> s;
		if(a==1)
		{
			int j;
			cin >> j;
			mp[s]+=j;
		}
		else if(a==2)
			mp.erase(s);
		else
			cout << mp[s] << "\n";
	}
	return 0;
}