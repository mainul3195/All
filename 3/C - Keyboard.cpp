#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	string s;
	while(getline(cin , s))
	{
		for(int i=0; s[i]; i++)
		{
			bool flag=1;
			for(int j=0; j<a.size(); j++)
			{
				if(a[j]==s[i])
				{
					cout << a[j-1];
					flag=0;
					break;
				}
			}
			if(flag)
				cout << s[i];
		}
		cout << "\n";
	}
	return 0;
}