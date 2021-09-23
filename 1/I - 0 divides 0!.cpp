#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2)
int t[785];
vector<long long> prime;
void sieve()
{
	prime.push_back(2);
	for(int i=3; i<=223; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=50000; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(int i=3; i<=50000; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	return ;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	int n,m;
	while(cin >> n >> m)
	{
		int y=m;
		int z=n;
		if(!n)
			n=1;
		if(m<=n)
		{
			cout << m << " divides " << z << "!\n";
			continue;
		}

		map<int , int > mforn, mform;
		for(int i=0; prime[i]<=n && prime[i]*prime[i]<=m; i++)
		{
			int x=n;
			int count=0;
			while(x)
			{
				count+=x/prime[i];
				x/=prime[i];
			}
			if(count)
				mforn[prime[i]]+=count;
		}
		for(int i=0; prime[i]*prime[i]<=m; i++)
		{
			int count=0;
			while(!(m%prime[i]))
			{
				count++;
				m/=prime[i];
			}
			if(count)
				mform[prime[i]]+=count;
		}
		bool flag=1;
		if(m>n)
			flag=0;
		else
			for(auto it=mform.begin(); it!=mform.end(); it++)
				if(mforn[it->first]<it->second)
				{
					flag=0;
					break;
				}
		if(flag)
			cout << y << " divides " << z << "!\n";
		else
			cout << y << " does not divide " << z << "!\n";
	}
	return 0;
}