#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int>v(n+10);
	v[0]=v[1]=v[2]=0;
	v[3]=1;
	for(int i=4; i<=n; i++)
		v[i]=(v[i-1]+v[i-3])%1000000007;
	cout << v[n];
	return 0;
}