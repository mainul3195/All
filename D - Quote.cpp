#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	bool first=1;
	while(getline(cin, s))
	{
		for(int i=0; i<s.size(); i++)
		{
			if(s[i]=='\"')
			{
				if(first)
				{
					first=0;
					cout << "``";
				}
				else
				{
					first = 1;
					cout << "''";
				}
			}
			else
				cout << s[i];
		}
		cout << "\n";
	}
	return 0;
}