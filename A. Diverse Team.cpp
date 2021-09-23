#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin >> n >> k;
	set<int> num, pos;
	for(int i=1; i<=n; i++)
	{
		int j;
		cin >> j;
		if(num.find(j)==num.end())
		{
			num.insert(j);
			pos.insert(i);
		}
	}
	if(pos.size()<k)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		int c=0;
		for(auto i: pos)
		{
			c++;
			cout << i << " \n"[c==k];
			if(c==k)
				break;
		}
	}
	return 0;
}