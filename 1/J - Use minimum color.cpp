#include<bits/stdc++.h>
using namespace std;
void sieve(int n, int v[])
{
	int i, j;
	int sq=sqrt(n)+1;
	v[2]=1;
	for(i=4; i<=n; i+=2)
		v[i]=2;
	for(i=3; i<=sq; i+=2)
		if(!v[i])
		{
			v[i]=1;
			for(j=i*i; j<=n; j+=2*i)
				v[j]=2;
		}
	while(i<=n)
	{
		if(!v[i])
			v[i]=1;
		i+=2;
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int v[n+9]={0};
	sieve(n+5, v);
	if(n>=3)
		cout << "2\n";
	else
		cout << "1\n";
	for(int i=2; i<n+2; i++)
		cout << v[i] << " \n"[i==n+1];
	return 0;
}