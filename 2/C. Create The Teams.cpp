#include<bits/stdc++.h>
using namespace std;
void execute();
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--)
		execute();
	return 0;
}
void execute()
{
	vector <int> v;
	int i,n,x,d,a=0,b=0,p,s;
	cin >> n >> x;
	for(i=0; i<n; i++)
	{
		cin >> d;
		v.push_back(d);
	}
	sort(v.begin(), v.end());
	for(i=0; i<n; i++)
		cout << v[i] << "\n";
	for(i=0; i<n; i++)
		if(v[i]>=x)
			break;
	if(i!=n)
		a=n-i;
	for(i=0; i<n && v[i]<x; i++)
	{
		p=(x+v[i]-1)/v[i];
		s=(n-i)/p;
		if(s>b && v[i]*((n-i)/s)>=x)
			b=s;
	}
	if(b>a)
		a=b;
	cout << a << "\n";
	return;
}