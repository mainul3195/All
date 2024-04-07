#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    cout << "? 1 2 3\n";
    int r, prev, sim, scr;
    cin >> prev;
    vector<int> ans;
    for (int i = 2; i + 2 <= n; i++)
    {
        cout << "? " << i << " " << i + 1 << " " << i + 2 << "\n";
        cin >> r;
        if (r != prev)
        {
            if (r)
                scr = i + 2, sim = i - 1;
            else
                sim = i + 2, scr = i - 1;
            ans.push_back(sim);
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != sim && i != scr)
        {
            cout << "? " << sim << " " << scr << " " << i << "\n";
            cin >> r;
            if (!r)
                ans.push_back(i);
        }
    }
    cout << "! " << ans.size() << " ";
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    return;
}
int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
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