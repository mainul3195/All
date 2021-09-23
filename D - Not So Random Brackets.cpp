#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	map<char, char>mp;
	mp[')']='(';
	mp['}']='{';
	mp[']']='[';

	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		bool ok=1;
		stack<char>st;
		for(int i=0; s[i]; i++)
		{
			if(!st.empty() && mp.find(s[i])!=mp.end() && st.top()==mp[s[i]])
				st.pop();
			else if(!st.empty() && mp.find(s[i])!=mp.end() && st.top()!=mp[s[i]])
			{
				ok=0;
				break;
			}
			else
				st.push(s[i]);
		}
		if(ok && st.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}