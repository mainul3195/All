#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >>  n >> k;
    vector<long long> h(n), dp(n, 0);
    for(auto &i: h)
        cin >> i;
    dp[0] = 0;
    for(int i=1; i<n; i++)
    {
        long long l = max(0, i-k), tmp = 1000000000;
        for(int j=i-1; j>=l; j--)
            tmp = min(tmp, dp[j]+abs(h[i]-h[j]));
        dp[i] = tmp;
    }
    cout << dp[n-1] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
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