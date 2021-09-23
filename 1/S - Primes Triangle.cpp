#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2)
int t[1600000];
vector<int>prime;
void sieve()
{
	prime.push_back(2);
	for(int i=3; i<=10000; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=100000000; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(int i=3; i<=100000000; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
		return;
}
int find(int n)
{
	int l=0, r=prime.size()-1, mid, ans=-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(prime[mid]==n)
		{
			ans=mid;
			break;
		}
		if(prime[mid]<n)
			l=mid+1;
		else
			r=mid-1;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int pos=find(n);
		if(pos==-1)
		{
			cout << pos << "\n";
			continue;
		}
		int row=(sqrt(8*pos+1)-1)/2+1;
		int col=pos+1-(row*(row-1)/2);
		cout << row << " " << col << "\n";
	}
	return 0;
}