#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	int i;
	int m, l, r;
	vector<int>v;
	v.push_back(0);
	cin >> s;
	for(i=1; s[i]; i++)
	{
		l=v[i-1];
		v.push_back(l);
		if(s[i]==s[i-1])
			v[i]++;
	}

	cin >> m;
	while(m--)
	{
		cin >> l >> r;
		i=v[r-1]-v[l-1];
		cout << i << "\n";
	}
	return 0;
}
