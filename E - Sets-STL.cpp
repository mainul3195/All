#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	set<int>s;
	int a, x;
	while(q--)
	{
		//cout << "\t" << q << "\n";
		cin >> a >> x;
		if(a==1)
			s.insert(x);
		else if(a==2)
			s.erase(x);
		else 
		{
			if(s.find(x)!=s.end())
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
	return 0;
}