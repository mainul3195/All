#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> cnt(100005, 0), dp(100005, 0);
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        // cout << j << " ";
        cnt[j]++;
    }
    for (int i = 0; i <= 100000; i++)
        dp[i] = max((i > 0 ? dp[i - 1] : 0), i * cnt[i] + (i > 1 ? dp[i - 2] : 0));
    long long mx = 0;
    for (auto i : dp)
        mx = max(mx, i);
    cout << mx << "\n";
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