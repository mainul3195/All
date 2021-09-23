#include<bits/stdc++.h>
using namespace std;
#define last 1000000
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2) 
int t[last/64 + 2];
vector<int> nod(1000006,1),ans;
void calc()
{
	for(int i=2; i*i<=last; i++)
		for(int j=i; j<=last; j+=i)
				nod[j]++;
	for(int i=1; i<=last; i++)
		for(int j=i; j<=last; j+=i)
			if((nod[j] <4) || nod[j] % nod[i])
				cngbit(j);
	for(int i=1; i<=1000000; i++)
		if(!ckbit(i))
			ans.push_back(i);
	cout << ans[107];
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	calc();
	return 0;
}