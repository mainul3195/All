#include<bits/stdc++.h>
using namespace std;
int findgcd(int a, int b)
{
	if(!b)
		return a;
	return findgcd(b, a%b);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int gcd, i,j;
		vector<int>v;
		for(i=0; i<n; i++)
		{
			cin >> j;
			v.push_back(j);
		}
		gcd=v[0];
		int flag=0;
		for(i=1; i<n; i++)
		{
			gcd=findgcd(gcd, v[i]);
			if(gcd==1)
			{
				flag=1;
				break;
			}
		}
		if(flag)
			cout << n << "\n";
		else 
			cout << "-1\n";
	}
	return 0;
}