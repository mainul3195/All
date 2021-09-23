#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	char a[5000]={0}, b[5000]={0}, c[5000]={0};
	a[0]='1';
	b[0]='2';
	vector<string>v;
	v.push_back(a);
	v.push_back(b);
	int l1=1, l2=1;
	for(int i=2; i<=500; i++)
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
	for(int i=0; i<=500; i++)
		reverse(v[i].begin(), v[i].end());
	while(1)
	{
		string x,y;
		cin >> x >> y;
		if(x=="0" && y=="0")
			return 0;

		int l=0, h=500, mid, lind=-1, hind=-1;

		while(l<=h)
		{
			mid=(l+h)/2;
		//	cout << l << " " << h << " " << mid << "\n";
			if(v[mid].size()<y.size())
			{
				hind=mid;
				l=mid+1;
			}
			else if(v[mid].size()==y.size() && v[mid]<=y)
			{
				hind=mid;
				l=mid+1;
			}
			else
				h=mid-1;
		}
		//cout << hind << "\n";
		l=0,h=500;
		while(l<=h)
		{
			mid=(l+h)/2;
			if(v[mid].size()>x.size())
			{
				lind=mid;
				h=mid-1;
			}
			else if(v[mid].size()==x.size() && v[mid]>=x)
			{
				lind=mid;
				h=mid-1;
			}
			else
				l=mid+1;
		}
		//cout << lind << "\n";
		cout << hind-lind+1 << "\n";
	}
}