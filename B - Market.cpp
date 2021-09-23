#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector <int> a;
	vector <long long>b;
	long long p,q,r;
	int n, s, i, j, k;
	cin >> n>> s;
	a.push_back(0);
	b.push_back(0);
	for(i=1; i<=n; i++)
	{
		cin >> j;
		a.push_back(j);
		b.push_back(j);
	}
	int l=0, h=n, mid;
	while(l<=h)
	{
		mid=(l+h)/2;
		for(i=1; i<=n; i++)
			b[i]=a[i]+(long long)i*mid;
		sort(b.begin(), b.end());
		for(i=1, p=0; i<=mid; i++)
			p+=b[i];
		if(p==s) 
		{
			q=p,r=mid;
			break;
		}
		if(p>s) h=mid-1;
		else q=p,r=mid,l=mid+1;
	}
	if(n==1 && a[1] >= s) mid=0, p=0;
	cout << r << " " << q;
	return 0;
}