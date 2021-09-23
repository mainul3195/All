#include<bits/stdc++.h>
using namespace std;
uint64_t bigmod(uint64_t a, uint64_t d, uint64_t n)
{
	if(d==1)
		return a;
	__uint128_t temp = bigmod(a, d/2, n);
	temp= (temp*temp)%n;
	if(d&1)
		temp = (temp*a)%n;
	return temp;
}
bool ck(int a, int p, uint64_t n, uint64_t t)
{
	uint64_t x=bigmod(a,t,n);
	if(x==1 || x==n-1)
		return 1;
	for(int i=0; i<p; i++)
	{
		x= ( __uint128_t )x*x %n;
		if(x==n-1)
			return 1;
	}
	return 0;
}
bool miller_robin(uint64_t n)
{
	if(n<4)
		return n==2 || n==3;
	uint64_t remainder=n-1;
	int power=0;
	while(!(remainder & 1)) 
	{
		power++;
		remainder>>=1;
	}
	for(int a : {2,3,5,7,11,13,17,19,23,29,31,37})
	{
		if(a>=n-1)
			break;
		if(!ck(a, power, n, remainder))
			return 0;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		uint64_t n;
		cin >> n;
		if(miller_robin(n))	
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}