#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[x/64]&(1<<((x%64)/2)))
#define cngbit(x) (t[x/64]|=(1<<((x%64)/2)))
int t[2000000];
vector<int> prime;
void sieve(){
	int i,j;
	prime.push_back(2);
	for(i=3; i<=10000; i+=2)
		if(!ckbit(i))
			for(j=i*i; j<=100000000; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(i=3; i<=100000000; i+=2)
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
		int k;
		cin >> k;
		cout << prime[k-1] << "\n";
	}
	return 0;
}