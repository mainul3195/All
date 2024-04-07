#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[x/64]&(1<<((x%64)/2)))
#define cngbit(x) (t[x/64]|=(1<<((x%64)/2)))
int t[2000000];
void sieve()
{
	int i,j;
	for(i=3; i<=10000; i+=2)
		if(!ckbit(i))
			for(j=i*i; j<=100000000; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	// for(i=0; i<=25; i++)
	// {
	// 	int k=ckbit(i);
	// 	cout << k << "\n";
	// }
	int cnt=1;
	cout << "2\n";
	for(i=3; i<=100000000; i+=2)
		if(!ckbit(i) && ++cnt%100==1)
			cout << i << "\n";
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	return 0;
}