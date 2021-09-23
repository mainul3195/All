#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/64] & ( 1 << ((x)%64)/2))
#define cngbit(x) (t[(x)/64] |= ( 1 << ((x)%64)/2))

int t[800000];
vector<int> v;
void sieve()
{
	int i,j;
	for(i=3; i<=6325; i+=2)
		if(!ckbit(i))
			for(j=i*i; j<=40000000; j+=2*i)
				cngbit(j);
	for(i=3; i<=30000000; i+=2)
		if(!ckbit(i) && !ckbit(i+2))
			v.push_back(i);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	int n;
	while(cin >> n)
		cout << "(" << v[n-1] << ", " << v[n-1]+2 << ")\n";
	return 0;
}