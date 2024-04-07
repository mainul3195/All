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
	vector<int>ans(n);
	int ind=0; 
	for(int i=1; i<n; i+=2)
		ans[i]=v[ind++];
	for(int i=0; i<n; i+=2)
		ans[i]=v[ind++];
	int c=0;
	for(int i=1; i<n-1; i++)
		if(ans[i]<ans[i-1] && ans[i]<ans[i+1])
			c++;
	cout << c <<  "\n";
	for(int i=0; i<n; i++)
		cout << ans[i] << " \n"[i==n-1];
	return 0;
}