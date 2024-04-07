#include<iostream>
//#include<pair>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<pair<int, int>> v;
	for(int i=0; i<n; i++)
	{
		int j,k;
		cin >> j >> k;
		v.push_back({j,k});
	}
	sort(v.begin(), v.end());
	long long ans=0;
	for(auto i: v)
	{
		if(i.second>m)
		{
			ans+=(long long)m*i.first;
			break;
		}
		else
		{
			ans+=(long long)i.second*i.first;
			m-=i.second;
		}
	}
	cout << ans << "\n";
	return 0;
}