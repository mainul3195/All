#include <bits/stdc++.h>
using namespace std;
set<long long> st;
long long n;
bool ok()
{
    for (auto i : st)
        if (st.find(n - i) != st.end())
            return 1;
    return 0;
}
void solve()
{
    cin >> n;
    if (ok())
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (long long i = 1; i <= 30000; i++)
        st.insert(i * i * i);
    // for (auto i : st)
    //     cout << i << "\n";
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