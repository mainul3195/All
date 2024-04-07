#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base:: sync_with_stdio(0); cin.tie(0);
	int f=1, i, j, n, tmp;
	vector <int> v;
	cin >> n >> tmp;
	v.push_back(tmp);
	n*=2;
	for(i=1; i<n; i++)
	{
		cin >> j;
		v.push_back(j);
		if(j!=tmp)
			f=0;
	}
	if(f)
	{
		cout << "-1";
		return 0;
	}
	sort(v.begin(), v.end());
	for(i=0; i<n; i++)
	{
		cout << v[i];
		if(i==n-1) return 0;
		cout << " ";
	}
}