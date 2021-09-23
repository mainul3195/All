#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	while(cin >> s)
	{
		int i,j,l;
		l=s.size();
		for(i=l-1; i>=0; i--)
			if(s[i]=='[')
				for(j=i+1; s[j] != '[' && s[j] != ']' && s[j]; j++)
					cout << s[j];

		for(i=0; i<l; i++)
		{
			if(s[i]=='[')
			{
				for(i++; s[i] != '[' && s[i] != ']' && s[i]; i++);
				i--;
			}
			else
				if(s[i] != ']')
					cout << s[i];
		}
		cout << "\n";
	}
	return 0;
}