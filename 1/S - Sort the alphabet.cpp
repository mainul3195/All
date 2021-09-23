#include<bits/stdc++.h>
using namespace std;
vector<int> indeg(26), node[26];
string ans;
bool topsort()
{
	set<int>s;
	for(int i=0; i<26; i++)
		if(!indeg[i])
			s.insert(i);
	while(!s.empty())
	{
		int t= *s.begin();
		ans += t+97;
		s.erase(s.begin());
		for(int i: node[t])
		{
			indeg[i]--;
			if(!indeg[i])
				s.insert(i);
		}
	}
	for(int i=0; i<26; i++)
		if(indeg[i])
			return 0;
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string s[n];
	map<string, int> mp;
	for(int i=0; i<n; i++)
		cin >> s[i];
	for(int i=0; i<n-1; i++)
		for(int j=i+1,k; j<n; j++)
		{
			for(k=0; s[i][k] == s[j][k]; k++);
			string t;
			t+=s[i][k];
			t+=s[j][k];
			if(s[i][k] && !s[j][k])
			{
				cout << "Impossible\n";
				return 0;
			}
			if(s[i][k] && mp.find(t) == mp.end())
			{
				node[s[i][k]-97].push_back(s[j][k]-97);
				indeg[s[j][k]-97]++;
			}
		}
	if(!topsort())
		cout << "Impossible\n";
	else
		cout << ans << "\n";
	return 0;
}