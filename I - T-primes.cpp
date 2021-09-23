#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2)
int t[100000];
void sieve()
{
	cngbit(1);
	int i,j;
	for(i=3; i<=2000; i+=2)
		if(!ckbit(i))
			for(j=i*i; j<=4000000; j+=2*i)
				if(!ckbit(j))
					cngbit(j);

}
void execute()
{
	long long n ;
	cin >> n;
	long long sq=sqrt(n);
	if((sq%2 || sq==2) && sq*sq==n && !(ckbit(sq)))
		cout << "YES\n";
	else
		cout << "NO\n";
	return ;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	int t;
	cin >> t;
	while(t--)
		execute();
	return 0;
}