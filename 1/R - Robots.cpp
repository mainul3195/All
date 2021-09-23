#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		int n,i,j,k;
		pair<int, int> p = {0,0};
		map < pair < int, int> , int > mp;
		mp[p]=0;
		cin >> n;
		int l=-1, r=n;
		cin >> s;
		for(i=0; s[i]; i++)
		{
			if(s[i]=='L')
				p.first--;
			else if(s[i]=='R')
				p.first++;
			else if(s[i]=='U')
				p.second++;
			else if(s[i]=='D')
				p.second--;
			if(mp.count(p) && i-mp[p]+1 < r-l+1)
				l=mp[p]+1, r=i+1;
			mp[p]=i+1;
		}
		if(l==-1)
			cout << "-1\n";
		else
			cout << l << " " << r << "\n";
	}
	return 0;
}