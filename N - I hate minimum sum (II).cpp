#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,a,i,j;
	while(cin >> n)
	{
		int ar[n+1][n+1];
		for(i=0, j=0; j<=n; j++) 
			ar[i][j]=ar[j][i]=0;
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
			{
				cin >> a;
				ar[i][j]=a;
			}

		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				ar[i][j]+=ar[i-1][j]+ ar[i][j-1]-ar[i-1][j-1];
		// for(i=0; i<=n; i++)
		// 	for(j=0; j<=n; j++)
		// 		cout << ar[i][j] << " \n"[j==n];
		int t,p,q,max=-1000000000;
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				for(p=i; p<=n; p++)
					for(q=j; q<=n; q++)
					{
						t=ar[p][q]-ar[p][j-1]-ar[i-1][q]+ar[i-1][j-1];
						if(t>max)
							max=t;
					}
		cout << max << "\n";	
	}
	
	return 0;
}