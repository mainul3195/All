#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define mx 2000000
int main()
{
	vector<int>inv(mx+1), invfact(mx+1), fact(mx+1);
	inv[1]=1;
	fact[0]=1;
	for(int i=1; i<=mx; i++)
		fact[i]=i*(long long)fact[i-1] % M;
	for(int i=2; i<=mx; i++)
		inv[i]=(M-(M/i))*(long long)inv[M%i] %M;
	invfact[0]=1;
	for(int i=1; i<=mx; i++)
		invfact[i]=inv[i]*(long long)invfact[i-1] % M; 
	int t, tc=0;;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		cout << "Case " << ++tc << ": " <<  ((((long long)fact[n+k-1]*invfact[k-1])%M) * ( invfact[n]) ) %M << "\n";
	}
	return 0;
}