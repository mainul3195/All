#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >>m;
	map<string, string> mp;
	string a, b;
	for(int i=0; i<n; i++)
	{
		cin >> a >> b;
		b+=";";
		mp[b]=a;
	}
	for(int i=0; i<m; i++)
	{
		cin >> a >> b;
		cout << a << " " << b << " #" << mp[b] << "\n";
	}
	return 0;
}