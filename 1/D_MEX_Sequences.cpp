#include<bits/stdc++.h>
#define mod 998244353
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> dp1(n+2, 0), dp2(n+2, 0);
    dp1[0] = 1;
    int m = n;
    while(n--)
    {
        long long x;
        cin >> x;
        if(x>0)
            dp2[x-1] = (dp1[x-1] + 2*dp2[x-1]) % mod;
        dp1[x+1] = (dp1[x] + 2*dp1[x+1])%mod;
        dp2[x+1] = (2*dp2[x+1])%mod;
    }
    long long ans = 0;
    for(int i = 0; i<=m; i++)
        ans = (ans + dp1[i]+dp2[i])%mod;
    cout << (ans-1+mod)%mod << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve(); 
    return 0;
}

/*
gcd
lcm
modfact
fact
pfsingle
pfmultiple
ncrsingle
ncrmod
bgmod
mdinverse
sieve
SegmentTree
kmp
bit
sparseTable
vll
pi
ll
Pair
all
mll
mii
mis
msi
vvi
vi
pb
inf
linf
*/