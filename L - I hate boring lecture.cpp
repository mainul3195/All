#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector <int> a;
	int i,sum=0,j;
	a.push_back(0);
	for(i=0; i<n; i++)
	{
		cin >> j;
		a.push_back(j);
	}
	for(i=1; i<=n; i++)
	{
		cin >> j;
		if(j)
		{
			sum+=a[i];
			a[i]=0;
		}
	}
	for(i=1; i<=n; i++)
		a[i] += a[i-1];
	int max=0;
	for(i=k; i<=n; i++)
		if(a[i]-a[i-k]>max)
			max=a[i]-a[i-k];
	sum += max;
	cout << sum;
	return 0;
}