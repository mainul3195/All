#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ind, num;
vector<vector<int>> dp;
bool cmp(int &a, int &b)
{
    return num[a] < num[b] || (num[a] == num[b] && a < b);
}
int okdone(int i = 1, int T = 1)
{
    if(i>n)
        return 0;
    if(T>2*n)
        return 214748364;
    if(~dp[i][T])
        return dp[i][T];
    return dp[i][T] = min(okdone(i, T + 1), abs(num[ind[i]] - T) + okdone(i + 1, T + 1));
}
void solve()
{
    cin >> n;
    ind = vector<int>(n + 1);
    num = vector<int>(n + 1, 0);
    dp = vector<vector<int>>(n + 1, vector<int>(2 * n + 1, -1));
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        ind[i] = i;
    }
    sort(ind.begin(), ind.end(), cmp);
    cout << okdone() << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
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