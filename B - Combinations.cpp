#include<bits/stdc++.h>
using namespace std;
#define M 1000003
int main()
{
	vector<long long>inv(1000001), invfact(1000001), fact(1000001);
	inv[1]=1;
	fact[0]=1;
	for(int i=1; i<=1000000; i++)
		fact[i]=i*fact[i-1] % M;
	for(int i=2; i<=1000000; i++)
		inv[i]=(M-(M/i))*inv[M%i] %M;
	invfact[0]=1;
	for(int i=1; i<=1000000; i++)
		invfact[i]=inv[i]*invfact[i-1] % M; 
	int t, tc=0;;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		cout << "Case " << ++tc << ": " <<  (((fact[n]*invfact[k])%M) * ( invfact[n-k]) ) %M << "\n";
	}
	return 0;
}