#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> v;
vector<vector<long long>> dp;
long long okdone(int i = 0, int j = n - 1)
{
    if (i == j)
        return 0;
    if (~dp[i][j])
        return dp[i][j];
    return dp[i][j] = v[j] - v[i] + min(okdone(i + 1, j), okdone(i, j - 1));
}
void solve()
{
    cin >> n;
    v = vector<long long>(n);
    dp = vector<vector<long long>>(n, vector<long long>(n, -1));
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
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