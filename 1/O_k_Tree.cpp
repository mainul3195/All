#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long n, k, d;
vector<vector<long long>> dp;

long long okdone(int done = 0, int rem = n)
{
    if (rem < 0)
        return 0;
    if (!rem && done)
        return 1;
    if (~dp[done][rem])
        return dp[done][rem];
    long long tot = 0;
    for (int i = 1; i < d; i++)
        tot = (tot + okdone(done, rem - i)) % mod;
    for (int i = d; i <= k; i++)
        tot = (tot + okdone(1, rem - i)) % mod;
    return dp[done][rem] = tot;
}
void solve()
{
    cin >> n >> k >> d;
    dp = vector<vector<long long>>(2, vector<long long>(n + 1, -1));
    cout << okdone() << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
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