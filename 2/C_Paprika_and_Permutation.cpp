#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    multiset<int> in, out;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        if(in.find(j)==in.end() && j<=n)
            in.insert(j);
        else
            out.insert(j);
    }
    int nxt = 1;
    bool ok = 1;
    int ans = 0;
    while (nxt != n + 1)
    {
        if (in.size() && nxt == *in.begin())
        {
            in.erase(in.begin());
            nxt++;
        }
        else
        {
            int bg = *out.begin();
            if (bg <= 2 * nxt)
            {
                ok = !ok;
                break;
            }
            ans++;
            nxt++;
            out.erase(out.begin());
        }
    }
    if (ok)
        cout << ans << "\n";
    else
        cout << "-1\n";
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