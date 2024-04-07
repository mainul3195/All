#include <bits/stdc++.h>
using namespace std;
vector<long long> coins = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
vector<vector<long long>> dp;
int n;
long long okdone(long long i = 0, long long rem = n)
{
    if (!rem)
        return 1;
    if (i == 11 || rem < 0)
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
    dp = vector<vector<long long>>(11, vector<long long>(30004, -1));
    double d;
    while (scanf("%lf", &d) && d != 0)
    {
        n = d * 1000;
        if (n % 10 >= 5)
            n += 10;
        n /= 10;
        printf("%6.2lf%17lld\n", d, okdone());
    }
    return;
}
int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
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