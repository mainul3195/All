#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long ans = 0;
    map<char, long long>mp;
    string s;
    cin >> s;
    for(auto i: s)
    {
        mp[i]++;
        ans += mp[i];
    }
    cout << ans*2 - s.size() << "\n";
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