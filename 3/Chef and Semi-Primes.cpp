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
		bool ok=0;
		for(int j=1; j<n; j++)
		{
			vector<int> v1, v2;
			for(int i=2, num=j; num>1; i++)
			{
				while(!(num%i))
				{
					v1.push_back(i);
					num/=i;
				}
			}
			for(int i=2, num=n-j; num>1; i++)
			{
				while(!(num%i))
				{
					v2.push_back(i);
					num/=i;
				}
			}
			if(v1.size()==2 && v1[0] != v1[1] && v2.size()==2 && v2[0] != v2[1])
			{
				ok=1;
				break;
			}
		}
		if(ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}