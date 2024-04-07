#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[x/64]&(1<<((x%64)/2)))
#define cngbit(x) (t[x/64]|=(1<<((x%64)/2)))
int t[2000000];
vector<long long> prime;
void sieve(){
	int i,j;
	prime.push_back(2);
	for(i=3; i<=1000; i+=2)
		if(!ckbit(i))
			for(j=i*i; j<=1000000; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(i=3; i<=1000000; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	int q ;
	cin >> q;
	while(q--)
	{
		long long k;
		cin >> k;
		long long r=k-1;
		long long l=r-2000;
		if(l<0)
			l=0;
		int sg[2005]={0};
		long long start, end, i,j;
		for(i=0; prime[i]*prime[i]<=r; i++)
		{
			start=((l+prime[i]-1)/prime[i])*prime[i];
			while(start<l || start==prime[i])
				start+=prime[i];
			//cout << start << "\n";
			for(j=start; j<=r; j+=prime[i])
				sg[j-l]=1;
		}
		for(i=r-l; i>=0; i--)
			if(!sg[i])
			{
				cout << i+l << "\n";
				break;
			}
	}
	return 0;
}