#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		int i=0;
		while(s[i]=='0' && s[i++]);
		while(s[i])
			cout << s[i++];
		cout << "\n";
	}
	return 0;
}