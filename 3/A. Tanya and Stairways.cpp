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
	vector<int> ans;
	for(int i=0; i<n; i++)
		if(v[(i+1)%n]==1)
			ans.push_back(v[i]);
	cout << ans.size() << "\n";
	for(int i=0; i<ans.size(); i++)
		cout << ans[i] << " \n"[i==ans.size()-1];
	return 0;
}