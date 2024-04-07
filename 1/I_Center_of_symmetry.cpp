#include <bits/stdc++.h>
using namespace std;
struct point
{
    long long x, y;
    bool operator<(const point &a) const
    {
        return (x < a.x || (x == a.x && y < a.y));
    }
    point operator-(const point &a) const
    {
        return {x - a.x, y - a.y};
    }
};
void solve()
{
    int n;
    cin >> n;
    set<point> st;
    long long totx = 0, toty = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        st.insert({x, y});
        totx += x;
        toty += y;
    }
    point mid = {2 * totx / n, 2 * toty / n};
    bool ok = true;
    for (auto i : st)
        if (st.find(mid - i) == st.end())
        {
            ok = !ok;
            break;
        }
    if (ok)
        cout << "yes\n";
    else
        cout << "no\n";

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