#include <bits/stdc++.h>
using namespace std;
vector<int> ac;
vector<vector<int>> dp;
int n;
long long okdone(int i = 0, int prev = 3)
{
    if (i == n)
        return 0;
    if (~dp[i][prev])
        return dp[i][prev];
    long long a = 1 + okdone(i + 1, 0);
    if (ac[i] == 1 && prev != 1)
        a = min(a, okdone(i + 1, 1));
    else if (ac[i] == 2 && prev != 2)
        a = min(a, okdone(i + 1, 2));
    else if (ac[i] == 3)
    {
        if (prev != 1)
            a = min(a, okdone(i + 1, 1));
        if (prev != 2)
            a = min(a, okdone(i + 1, 2));
    }
    return dp[i][prev] = a;
}
void solve()

{
    cin >> n;
    ac = vector<int>(n);
    for (auto &i : ac)
        cin >> i;
    dp = vector<vector<int>>(n + 1, vector<int>(4, -1));
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