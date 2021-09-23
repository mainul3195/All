#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		vector < int > a, b(n+1, 0);
		a.push_back(0);
		int i,j;
		for(i=0; i<n; i++)
		{
			cin >> j;
			a.push_back(j);
		}
		for(i=2; i<n; i++)
			if(a[i]>a[i-1] && a[i]>a[i+1])
				b[i]=1;
		for(i=1; i<=n; i++)
			b[i] += b[i-1];
		int ind=1,c=0;
		for(i=k; i<=n; i++)
			if(b[i-1]-b[i-k+1]>c)
			{
				c=b[i-1]-b[i-k+1];
				ind = i-k+1;
			}
		c++;
		cout << c << " " << ind << "\n";
	}
}