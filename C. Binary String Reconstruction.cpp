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
		int x;
		cin >> s >> x;
		int n=s.size();
		vector<char> w(n, 49);
		for(int i=0; i<n; i++)
			if(s[i]=='0')
			{
				if(i-x>=0)
					w[i-x]='0';
				if(i+x <n)
					w[i+x]='0';
			}
		bool ok=1;
		for(int i=0; i<n; i++)
		{
			if(s[i]=='1')
			{
				if(i-x>=0 && w[i-x]=='1')
					continue;
				if(i+x<n && w[i+x]=='1')
					continue;
				ok=0;
				break;
			}
		}
		if(!ok)
			cout << "-1\n";
		else
		{
			for(auto c: w)
				cout << c;
			cout << "\n";
		}
	}
	return 0;
}