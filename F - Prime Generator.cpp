#include<bits/stdc++.h>
using namespace std;
#define ckbit(x,y) (y[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x,y) (y[(x)/64] |= 1 << ((x)%64)/2)
int t[100000];
vector <long long > prime;
void sieve()
{
	int i,j;
	prime.push_back(2);
	for(i=3; i<=2000; i+=2)
		if(!ckbit(i,t))
			for(j=i*i; j<=4000000; j+=2*i)
				if(!ckbit(j,t))
					cngbit(j,t);
	for(i=3; i<=4000000; i+=2)
		if(!ckbit(i,t))
			prime.push_back(i);
	//	cout << prime[0] << "\n";
}
void segmented_sieve(long long l, long long r)
{
	long long start;
	int sg[10000]={0};
	if(l<=2 && r>=2)
		cout << 2 << "\n";
	long long lim=sqrt(r);
	for(int i=1; prime[i]<=lim; i++)
	{
		start=((l+prime[i]-1)/prime[i])*prime[i];
		if(prime[i]*prime[i]>start)
			start=prime[i]*prime[i];
		while(start<l || start==prime[i])
			start+=prime[i];
		if(!(start%2))
			start+=prime[i];
		//cout << start << " " << l << " " << r << "\n";
		while(start<=r)
		{
			//cout << start << "\n";
			cngbit(start-l,sg);
			start+=2*prime[i];		
		}
	}
	//cout << sg[0];
	//cngbit(5, sg);
	// for(int i=0; i<=11; i++)
	// 	cout << !(!(sg[0] & 1 << i)) << "\n";
	// cout << "\n";
	long long i=l;
	if(!(i%2))
		i++;
	for(; i<=r; i+=2)
		if(!ckbit(i-l, sg) && i!=1)
			cout << i << "\n";
	return ;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	int t;
	cin >> t;
	while(t--)
	{
		long long m,n;
		cin >> m >> n;
		segmented_sieve(m,n);
		if(t) cout << "\n";
	}
}