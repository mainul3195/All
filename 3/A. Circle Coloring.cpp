#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int>a(n),b(n),c(n),p(n);
		for(int i=0; i<n; i++)
			cin >> a[i];
		for(int i=0; i<n; i++)
			cin >> b[i];
		for(int i=0; i<n; i++)
			cin >> c[i];
		p[0]=a[0];
		for(int i=1; i<n-1; i++)
		{
			if(p[i-1]!=a[i])
				p[i]=a[i];
			else if(p[i-1]!=b[i])
				p[i]=b[i];
			else if(p[i-1]!=c[i])
				p[i]=c[i];
		}
		if(p[n-2]!=a[n-1] && p[0]!=a[n-1])
			p[n-1]=a[n-1];
		else if(p[n-2]!=b[n-1] && p[0]!=b[n-1])
			p[n-1]=b[n-1];
		else if(p[n-2]!=c[n-1] && p[0]!=c[n-1])
			p[n-1]=c[n-1];
		for(int i=0; i<n; i++)
			cout << p[i] << " \n"[i==n-1];
	}
	return 0;
}