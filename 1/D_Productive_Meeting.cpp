#include <bits/stdc++.h>
using namespace std;
struct pr
{
    long long a, b;
    bool operator<(const pr &x) const { return a < x.a || (a == x.a && b < x.b); }
};

void solve()
{
    int n;
    cin >> n;
    set<pr> st;
    vector<pr> ans;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        if (j)
            st.insert({j, i + 1});
    }
    while (st.size() > 1)
    {
        auto it1 = st.begin();
        auto it2 = st.end();
        it2--;
        auto [v1, i1] = *it1;
        auto [v2, i2] = *it2;
        ans.push_back({i1, i2});
        if (v1 > 1)
            st.insert({v1 - 1, i1});
        if (v2 > 1)
            st.insert({v2 - 1, i2});
        st.erase(it1);
        st.erase(it2);
    }
    cout << ans.size() << "\n";
    for (auto [i, j] : ans)
        cout << i << " " << j << "\n";
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