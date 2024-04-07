#include <bits/stdc++.h>
using namespace std;
struct nd
{
    long long l, r, c;
    bool operator<(const nd &a) const
    {
        return l < a.l || (l == a.l && r < a.r) || (l == a.l && r == a.r && c < a.c);
    }
};
struct Lft
{
    long long l, c;
    bool operator<(const Lft &a) const
    {
        return l < a.l || (l == a.l && c < a.c);
    }
};
struct Rgt
{
    long long r, c;
    bool operator<(const Rgt &a) const
    {
        return r > a.r || (r == a.r && c < a.c);
    }
};
void solve()
{
    int n;
    cin >> n;
    set<Rgt> s2;
    set<Lft> s1;
    map<nd, bool> mp;
    long long l, r, c;
    while (n--)
    {
        cin >> l >> r >> c;
        s2.insert({r, c});
        s1.insert({l, c});
        mp[{l, r, c}] = 1;
        auto [l, c1] = *s1.begin();
        auto [r, c2] = *s2.begin();
        long long a1, a2;
        a1 = a2 = 92233720368547758;
        if (mp.find({l, r, c1}) != mp.end())
            a1 = c1;
        if (mp.find({l, r, c2}) != mp.end())
            a2 = c2;
        cout << min({a1, a2, c1 + c2}) << "\n";
    }
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