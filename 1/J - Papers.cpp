#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		map<char, int> mp,price;
		char c;
		int tm;
		while(n--)
		{
			cin >> c >> tm;
			mp[c]=0;
			price[c]=tm;
		}
		cin >> n;
		string s;
		getline(cin, s);
		while(n--)
		{
			getline(cin , s);
			//cout << s << "\n";
			for(int i=0; s[i]; i++)
				if(mp.find(s[i])!=mp.end())
					mp[s[i]]++;
		}
		int tot=0;
		for(auto i1=mp.begin(), i2=price.begin(); i1!=mp.end(); ++i1, ++i2)
			tot+=i1->second*i2->second;
		cout << fixed << setprecision(2) <<  tot/100.0 << "$" << "\n";
	}
	return 0;
}