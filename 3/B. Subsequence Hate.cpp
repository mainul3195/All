#include<bits/stdc++.h>
using namespace std;
int min(int, int);
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> s;
		int i, j, no0, no1, c0, c1, mn=1e5;
		no0=no1=c0=c1=0;
		for(i=0; s[i]; i++)
		{
			if(s[i]=='1')
				no1++;
			else no0++;
		}
		if(no0==s.size() || no1==s.size()) mn=0;
		for(i=0; s[i]; i++)
		{
			if(s[i]=='1')
				c1++;
			else c0++;
			mn=min(mn, min(c0+no1-c1, c1+no0-c0));
		}
		cout << mn << "\n";
	}
	return 0;
}
int min(int a, int b)
{
	if(a<b)
		return a;
	return b;
}