#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin >> n >> k;
	int x;
	vector<pair<int, int> > v;
	vector<int> track(n,0),ans;
	for(int i=0; i<n; i++)
	{
		cin >> x ;
		v.push_back({x,i});
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int sum=0;
	for(int i=0; i<k; i++)
		sum+=v[i].first;
	cout << sum << "\n";
	for(int i=0; i<k; i++)
		track[v[i].second]=1;
	ans.push_back(-1);
	for(int i=0; i<n; i++)
		if(track[i])
			ans.push_back(i);
	ans.push_back(n-1);
	for(int i=1; i<k; i++)
		cout << ans[i]-ans[i-1] << " ";
	cout << ans[k+1]-ans[k-1] << "\n";
	return 0;
}