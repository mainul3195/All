#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int mn=1199999999;
	for(int i=k-1; i<n; i++)
		if(v[i]-v[i-k+1] < mn)
			mn=v[i]-v[i-k+1];
	cout << mn << "\n";
	return 0;
}