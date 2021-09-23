#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base:: sync_with_stdio(0);cin.tie(0);
	string s;
	cin >> s;
	int i,j,k,c=0;
	for(i=0; s[i]; i++)
	{
		if(s[i]=='=')
		{
			c++;
			if(c==1)
				cout << "username: ";
			else if(c==2)
				cout << "pwd: ";
			else if(c==3)
				cout << "profile: ";
			else if(c==4)
				cout << "role: ";
			else
				cout << "key: ";
			while(s[++i]!='&'&&s[i])
				cout << s[i];
			cout << "\n";
			i--;
		}
	}
	return 0;
}