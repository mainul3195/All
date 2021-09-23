#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	long long tot=0;
	for(int i=0; i<n; i++)
	{
		cin >> v[i];
		tot+=v[i];
	}
	long long t=0,mn=100000000000000000;
	for(int i=0; i<n-1; i++)
	{
		t+=v[i];
		mn=min(mn, abs(t*2 - tot));
	}
	cout << mn << "\n";
	return 0;
}