#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int count=0;
	vector<int>ans;
	for(int i=0, j=n-1; count<n; count++)
	{
		if(count%2)
			ans.push_back(v[i++]);
		else
			ans.push_back(v[j--]);
	}
	int c=0;
	for(int i=1; i<n-1; i++)
		if(ans[i]<ans[i-1] && ans[i]<ans[i+1])
			c++;
	cout << c << "\n";
	for(int i=0; i<n; i++)
		cout << ans[i] << " \n"[i==n-1];
	return 0;
}