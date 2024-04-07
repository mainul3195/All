#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >>  n;
    vector<long long> h(n), dp(n, 0);
    for(auto &i: h)
        cin >> i;
    dp[0] = 0;
    dp[1] = abs(h[0]-h[1]);
    for(int i=2; i<n; i++)
        dp[i] = min(dp[i-2]+abs(h[i]-h[i-2]), dp[i-1]+abs(h[i-1]-h[i]));
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