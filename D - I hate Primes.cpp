#include<bits/stdc++.h>
using namespace std;
int ar[31255],tr[1000000];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,t1,t2, r, s, t,i,j,sum,p,q;
	ar[0]|=1<<1;
	ar[0]|=1<<0;
	for(i=4; i<=1000000; i+=2)
	{
		p=i/32;
		q=i%32;
		ar[p]|=1<<q;
	}
	for(i=3; i<1000; i++)
	{
		p=i/32;
		q=i%32;
		if(!(ar[p]&1<<q))
			for(j=i*i; j<1000000; j+=2*i)
			{
				p=j/32;
				q=j%32;
				ar[p]|=1<<q;
			}
	}
	for(i=0; i<=1000000; i++)
	{
		p=i/32;
		q=i%32;
		if(!(ar[p] & 1<<q))
		{
			for(s=i, sum=0; s; s/=10)
				sum+=s%10;
			p=sum/32;
			q=sum%32;
			if(!(ar[p] & 1<<q))
				tr[i]=1;
		}
	}
	for(i=1; i<=1000000; i++)
		tr[i]+=tr[i-1];
	cin >> n;
	while(n--)
	{
		cin>>t1>>t2;
		j=tr[t2]-tr[t1-1];
		cout << j << "\n";
	}
	return 0;
}