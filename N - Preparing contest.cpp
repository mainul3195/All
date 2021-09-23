#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int>a,b;
	int i,j;
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
	//cout << n << " " << m << "\n";
	while(n>0 && m>0 && a[n-1]<b[m-1])
		n--,m--;
	//cout << n << " " << m << "\n";
	int count=0;
	for(i=0; i<n; i++)
	{
		int l=0,r=m-1, mid,flag=1;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(b[mid]==a[i])
			{
				flag=0;
				break;
			}
			else if(b[mid]>a[i])
				r=mid-1;
			else
				l=mid+1;
		}
		if(flag)
			count++;
	}
	cout << count;
	return 0;
}