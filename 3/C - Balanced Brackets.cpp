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
		cin >> s;
		int n=s.size();
		if(n&1)
		{
			cout << "NO\n";
			continue;
		}
		bool flag=1;
		stack<char> q;
		//cout << q.size() << "\n";
		for(int i=0; i<n; i++)
		{
			if(s[i]=='(' || s[i]=='{' || s[i]=='[')
			{
				q.push(s[i]);
				//cout << q.top() << "\n";
			}
			else if(s[i]==')' || s[i]=='}' || s[i]==']')
			{
				if(q.empty())
				{
					flag=0;
					break;
				}

				else if( s[i]==')' && q.top()=='(' || s[i]=='}'&& q.top()=='{' || s[i]==']' && q.top()=='[')
					q.pop();
				else
				{
					flag=0;
					break;
				}
			}
		}
		if(!q.empty())
			flag=0;
		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}