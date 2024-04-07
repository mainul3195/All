#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> track(m+2, 0);
	int l,r;
	for(int i=0; i<n; i++)
	{
		cin >> l >> r;
		track[l]++;
		track[r+1]--;
	}
	for(int i=1; i<m+2; i++)
		track[i]+=track[i-1];
	int c=0;
	for(int i=1; i<=m; i++)
		if(!track[i])
			c++;
	cout << c << "\n";
	if(c)
		for(int i=1, p=0; i<=m; i++)
			if(!track[i])
			{
				p++;
				cout << i << " \n"[p==c];
			}
	return 0;
}