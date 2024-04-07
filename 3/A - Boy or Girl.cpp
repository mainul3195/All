#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	map<int,int>mp;
	for(int i=0; i<s.size(); i++)
		mp[s[i]]=1;
	if(mp.size()%2)
		cout << "IGNORE HIM!\n";
	else
		cout << "CHAT WITH HER!\n";
	return 0;
}