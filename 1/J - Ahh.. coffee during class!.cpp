#include<bits/stdc++.h>
using namespace std;
long long ar[200005];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,q,k;
	cin >> n >> k >> q;
	int i,j;
	while(n--)
	{
		cin >> i >> j;
		ar[i]++;
		ar[j+1]--;
	}
	for(i=1; i<=200003; i++)
		ar[i]+=ar[i-1];
	for(i=1; i<=200003; i++)
	{
		if(ar[i]>=k) ar[i]=1;
		else ar[i]=0;
	}
	for(i=1; i<=200003; i++)
		ar[i]+=ar[i-1];
	while(q--)
	{
		cin >> i >> j;
		k=ar[j]-ar[i-1];
		cout << k << "\n";
	}
	return 0;
}