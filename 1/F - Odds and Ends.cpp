#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,i,a,b;
	vector<int>v;
	cin >> n;
	if(!(n%2))
	{
		cout << "No";
		return 0;
	}
	for(i=0; i<n; i++)
	{
		cin >> b;
		v.push_back(b);
	}
	if(v[0]%2 && v[n-1]%2)
	{
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}