#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m,n,c=0,i,j;
	vector<int>a,b;
	cin >> n >> m;
	for(i=0; i<n; i++)
	{
		cin >> j;
		a.push_back(j);
	}
	for(i=0; i<m ; i++)
	{
		cin >> j;
		b.push_back(j);
	}
	int max=0;
	for(i=0; i<n; i++)
	{
		int d=10230;
		for(j=0; j<m; j++)
		{
			if((a[i]&b[j])<d)
				d=a[i]&b[j];
		}	
		if(d>max)
			max=d;
	}
	c=max;
	for(i=0; i<n; i++)
	{
		int d=10230;
		for(j=0; j<m; j++)
		{
			if(((a[i]&b[j])|c)<d)
				d=(a[i]&b[j])|c;
		}
		c=d;
	}
	cout << c;
	return 0;
}