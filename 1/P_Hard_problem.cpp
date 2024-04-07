#include <bits/stdc++.h>
using namespace std;
vector<long long> c;
vector<vector<int>> dp;
vector<string> s;
int n;
long long okdone(int i = 0, int prev = 0 )
{
    if(i==n)
        return 
}
void solve()
{
    cin >> n;
    dp = vector<vector<int>>(n + 1, vector<int>(2, -1));
    c = vector<long long>(n);
    s = vector<string>(n);
    for (auto &i : c)
        cin >> i;
    for (auto &i : s)
        cin >> i;

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