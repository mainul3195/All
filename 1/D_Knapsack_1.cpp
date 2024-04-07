#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long  n, w;
    cin >> n >> w;
    vector<long long > dp(w+5, 0);
    long long  ans = 0;
    while(n--)
    {
        long long  wt, v;
        cin >> wt >> v;
        for(long long  i=w; i>=wt; i--)
        {
            dp[i] = max(dp[i], dp[i-wt]+v);
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << "\n";
    return;
}
int  main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long  t = 1;
    // cin >> t;
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
*/