#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	while(cin >> n)
	{
		if(!n)
			return 0;
		map<set<int> , int> mp;
		set<int>st;
		int t=n;
		while(n--)
		{
			for(int i=0; i<5; i++)
			{
				int j;
				cin >> j;
				st.insert(j);
			}
			mp[st]++;
			st.clear();
		}
		int mx=0;
		for(auto i: mp)
			if(i.second>mx)
				mx=i.second;
		int count=0;
		for(auto i:mp)
			if(i.second==mx)
				count++;
		cout << count*mx << "\n";
	}
	return 0;
}