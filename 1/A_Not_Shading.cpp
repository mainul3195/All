#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    r--, c--;
    vector<string> g(n);
    for (auto &i : g)
        cin >> i;
    if (g[r][c] == 'B')
        cout << "0\n";
    else
    {
        bool notfound = 1;
        for (auto i : g)
        {
            for (auto j : i)
                if (j == 'B')
                {
                    notfound = 0;
                    break;
                }
        }
        if (notfound)
            cout << "-1\n";
        else
        {
            bool pos = 0;
            for (int i = 0; i < m; i++)
                if (g[r][i] == 'B')
                {
                    pos = 1;
                    break;
                }
            for (int i = 0; i < n; i++)
                if (g[i][c] == 'B')
                {
                    pos = 1;
                    break;
                }
            if (pos)
                cout << "1\n";
            else
                cout << "2\n";
        }
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