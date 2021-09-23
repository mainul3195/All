#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	int n;
	cin >> n;
	cin >> s;
	int i, j, c, flag=0;
	for(i=0; i<n; i++)
		if(s[i]=='?')
		{
			c=0;
			while( i<n && s[i] == '?' )	
				c++,i++;
			if( (c==1 && ( i==1 || i==n || s[i]==s[i-2])) || c>=2)
			{
				flag=1;
				break;
			}
		}
	for(i=1; i<n; i++)
		if(s[i]!='?' && s[i-1]!='?' && s[i]==s[i-1])
		{
			flag=0;
			break;
		}
	if(flag)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}