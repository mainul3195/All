#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--)
	{
		string s;
		cin >> s;
		int mn=200, mx=0;
		int ar[200]={0};
		for(auto c: s)
		{
			ar[c]=1;
			mn=min(mn, (int)c);
			mx=max(mx, (int)c);
		}
		bool ok=1;
		for(int i=mn; i<=mx; i++)
			if(!ar[i])
			{
				ok=0;
				break;
			}
		if(mx-mn+1 == s.size() && ok)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}