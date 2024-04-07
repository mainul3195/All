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
		vector<long long> v;
		int i,j;
		for(i=0; i<n; i++)
		{
			cin >> j;
			v.push_back(j);
		}
		long long neg=0, pos=0;
		for(i=n-1; i>=0; i--)
		{
			if(v[i]<0)
				neg+=v[i];
			else
			{
				pos+=v[i];
				long long x=neg*(-1);
				long long d=min(v[i], x);
				pos-=d;
				neg+=d;
			}
		}
		cout << pos << "\n";
		v.clear();
	}
	return 0;
}