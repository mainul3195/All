#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, q;
		cin >> n >> q;
		vector<int> v(n);
		for(int i=0; i<n; i++)
			cin >> v[i];
		int sign=1;
		int mx=1;
		long long sum=0;
		int lastdig=0, lastval;
		for(int i=0; i<n;)
		{
			int mxm, mnm;
			if(mx)
			{
				mxm=v[i];
				while(++i<n && v[i]>=mxm)
					mxm=v[i];
				sum+=mxm;
				lastdig=0;
				mx=(++mx)%2;
			}
			else
			{
				mnm=v[i];
				while(++i<n && v[i]<=mnm)
					mnm=v[i];
				sum-=mnm;
				lastdig=1;
				lastval=mnm;
				mx=(++mx)%2;
			}
		}
		if(lastdig)
			sum+=lastval;
		cout << sum << "\n";
	}
	return 0;
}