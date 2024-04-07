#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a,b,ans;
	char c,t;
	string s;
	int count=0;
	while(cin >> a >> c >> b >> t >> s)
	{
		if(s[0]=='?')
			continue;
		ans=0;
		for(int i=0; s[i]; i++)
			ans=10*ans+s[i]-48;
		if(c=='-' && a-b == ans)
			count++;
		else if(c=='+' && a+b== ans)
			count++;
	}
	cout << count << "\n";
	return 0;
}