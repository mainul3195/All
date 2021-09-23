#include<bits/stdc++.h>
using namespace std;
int ar[1002][1002];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m,x=0;
	while(cin >> n >> m)
	{
		if(x) cout << "\n";
		x=1;
		int i,j,k,l;
		for(i=0; i<=n; i++)
			ar[0][i]=ar[i][0]=0;
		for(i=n; i>0; i--)
			for(j=1; j<=n; j++)
				cin >> ar[i][j];
// for(i=0; i<=n; i++)
// 	for(j=0; j<=n; j++)
// 		cout << ar[i][j] << " \n"[j==n];
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				ar[i][j] += ar[i-1][j] + ar[i][j-1] - ar[i-1][j-1];
		long long sum=0;
		for(i=n; i-m>=0; i--)
			for(j=m; j<=n; j++)
			{
				l=ar[i][j]-ar[i][j-m]-ar[i-m][j]+ar[i-m][j-m];
				cout << l << "\n";
				sum+=l;
			}
		cout << sum << "\n";
	}
	return 0;
}