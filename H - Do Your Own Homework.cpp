#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	int tc=0;
	while(t--)
	{
		int n;
		cin >> n;
		map<string, int> mp;
		string s;
		int num;
		while(n--)
		{
			cin >> s >> num;
			mp[s]=num;
		}
		int d;
		cin >> d >> s;
		cout << "Case " << ++tc << ": ";
		if(mp.find(s)==mp.end())
			cout << "Do your own homework!\n";
		else
		{
			if(mp[s]>d+5)
				cout << "Do your own homework!\n";
			else if(mp[s]<=d)
				cout << "Yesss\n";
			else
				cout << "Late\n";
		}
	}
	return 0;
}