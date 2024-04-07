#include<bits/stdc++.h>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	map<string, int> m;
	string a;
	a+=s[0];
	a+=s[1];
	m[a]++;
	for(int i=2; i<n; i++)
	{
		a.erase(a.begin(), a.begin()+1);
		a+=s[i];
		m[a]++;
	}
	int mx=0;
	for(auto i : m)
		if(i.second>mx)
			mx=i.second;
	for(auto i: m)
		if(i.second==mx)
		{
			cout << i.first;
			break;
		}
	return 0;
}