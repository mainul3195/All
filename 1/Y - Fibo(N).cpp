#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	char a[5000]={0}, b[5000]={0}, c[5000]={0};
	a[0]='0';
	b[0]='1';
	vector<string>v;
	v.push_back(a);
	v.push_back(b);
	int l1=1, l2=1;
	for(int i=2; i<=5000; i++)
	{
		int car=0,j;
		for(j=0; j<l2 || car; j++)
		{
			int d1=0,d2=0,sum=0;
			if(a[j])
				d1=a[j]-48;
			if(b[j])
				d2=b[j]-48;
			sum=car+d1+d2;
			car=sum/10;
			c[j]=sum%10+48;
		}
		l1=l2;
		l2=max(l2,j);
		v.push_back(c);
		for(int k=0; k<l1; k++)
			a[k]=b[k];
		for(int k=0; k<l2; k++)
			b[k]=c[k];
	}
	for(int i=0; i<=5000; i++)
		reverse(v[i].begin(), v[i].end());
	int n;
	while(cin >> n)
		cout << "The Fibonacci number for " << n << " is " << v[n] << "\n";
	return 0;
}