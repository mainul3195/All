#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	vector <int> v;
	cin >> n;
	int i,j;
	for(i=0; i<n; i++)
	{
		cin >> j;
		v.push_back(j);
	}
	for(i=0; i<n; i++)
	{
		cin >> j;
		v[i]-=j;
	}
	sort(v.begin(), v.end());
	int l=0, h=n-1,m,f=0,ind; 
	while(l<=h)
	{
		m=(l+h)/2;
		if(v[m]>0)
			h=m-1;
		else
			l=m+1;
	}
	if(l==n)
	{
		cout << "0";
		return 0;
	}
	long long count=0;
	for(i=l; i<n; i++)
	{
		f=v[i];
		l=0,h=i;
		while(l<=h)
		{
			m=(l+h)/2;
			if(v[m]+f>0)
				h=m-1;
			else
				l=m+1;
		}
		if(l!=i+1) count+=i-l;
	}
	cout << count;
	return 0;
}