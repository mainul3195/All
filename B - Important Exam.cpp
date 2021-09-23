#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long a[1005][6]={0},n,m,i,j,k,max[1005]={0};
	long long tot=0;
	char c;
	cin >> n >> m;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
		{
			cin >> c;
			a[j][c-65]++;
		}
	for(i=0; i<m; i++)
		for(j=0; j<5; j++)
			if(a[i][j]>max[i])
				max[i]=a[i][j];
	for(i=0; i<m; i++)
	{
		cin>>j;
		tot+=max[i]*j;
	}
	cout << tot;
	return 0;
}