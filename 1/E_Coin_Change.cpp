#include <bits/stdc++.h>
using namespace std;
vector<long long> coins = {1, 5, 10, 25, 50};
vector<vector<long long>> dp;
long long n;
long long okdone(long long i = 0, long long rem = n)
{
    if (!rem)
        return 1;
    if (i == 5 || rem < 0)
        return 0;
    if (~dp[i][rem])
        return dp[i][rem];
    long long tot = 0;
    for (long long j = 0; j * coins[i] <= rem; j++)
        tot += okdone(i + 1, rem - j * coins[i]);
    return dp[i][rem] = tot;
}
void solve()
{
    dp = vector<vector<long long>>(5, vector<long long>(8000 + 1, -1));
    while (cin >> n)
        cout << okdone() << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t = 1;
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