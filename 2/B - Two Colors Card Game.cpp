#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n;
	map<string, int> mp;
	string s;
	for(int i=0; i<n; i++)
	{
		cin >> s;
		mp[s]++;
	}
	cin >> m;
	for(int i=0; i<m; i++)
	{
		cin >> s;
		mp[s]--;
	}
	int mx=0;
	for(auto i:mp)
		if(i.second > mx)
			mx=i.second;
	cout << mx << "\n";
	return 0;
}