#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, s , i, j, k, ans=10000000, sum=0;
		cin >> n >> s;
		vector < int > v;
		for(i=0; i<n; i++)
		{
			cin >> j;
			v.push_back(j);
		}
		for(i=-1, j=0; i<n && j<n; )
		{
			if(sum<s)
			{
				if(++i==n) 
					break;
				sum+=v[i];
			}
			else
			{
				ans=min(ans, i-j+1);
				sum-=v[j++];
			}
		}
		if(ans==10000000)
			ans=0;
		cout << ans << "\n";
	}
	return 0;
}