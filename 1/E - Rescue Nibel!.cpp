#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int fact[300005], inv[300005], invfact[300005];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	fact[0]=1;
	for(int i=1; i<300004; i++)
		fact[i]=((long long)i*fact[i-1]) % mod;
	inv[1]=1;
	for(int i=2; i<300004; i++)
		inv[i] = ((long long)(mod - mod/i)*inv[mod%i]) % mod;
	invfact[0]=1;
	for(int i=1; i<300004; i++)
		invfact[i] = ((long long)inv[i]*invfact[i-1]) % mod;
	int n,k;
	cin >> n >> k;
	vector<pair<int,int>>v;
	multiset <int> st;
	for(int i=0; i<n; i++)
	{
		int j,k;
		cin >> j >> k;
		v.push_back({j,k});
	}
	sort(v.begin(), v.end());
	long long ans=0;
	for(int i=0; i<v.size(); i++)
	{
		auto it=st.lower_bound(v[i].first);
		st.erase(st.begin(), it);
		int x=st.size();
		st.insert(v[i].second);
		if(x>=k-1)
			ans = (ans + ((((long long)fact[x]*invfact[k-1])%mod)* invfact[x-k+1] ) %mod )%mod;
	}
	cout << ans;
	return 0;
}