#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k,i;
	cin >> n >> k;
	vector < int > v;
	v.push_back(0);
	int j;
	for(i=0; i<n; i++)
	{
		cin >> j;
		j+=v[i];
		v.push_back(j);
	}
	int min=1e9;
	for(i=k; i<=n; i++)
		if(v[i]-v[i-k]<min)
		{
			min=v[i]-v[i-k];
			j=i-k+1;
		}
	cout << j;
	return 0;
}