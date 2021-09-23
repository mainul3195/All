#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2)
int t[180];
vector<int>prime;
void sieve()
{
	prime.push_back(2);
	for(int i=3; i<=105; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=11000; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(int i=3; i<=11000; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	return ;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	int n;
	while(cin >> n)
	{
		if(!n)
			return 0;
		int sum,count=0;
		sum=2;
		int start=0, end=1;
		while(start<end)
		{
			//cout << "\t" << sum << "\n";
			if(sum==n)
			{
				count++;
				sum+=prime[end++];
			}
			else if(sum<n)
				sum+=prime[end++];
			else
				sum-=prime[start++];
		}
		cout << count << "\n";
	}
	return 0;
}