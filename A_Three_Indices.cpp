#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        int found1 = -1, found2 = -1;
        for (int j = i - 1; j >= 0; j--)
            if (v[j] < v[i])
            {
                found1 = j;
                break;
            }
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[i])
            {
                found2 = j;
                break;
            }
        if (found1 != -1 && found2 != -1)
        {
            cout << "YES\n";
            cout << found1 + 1 << " " << i + 1 << " " << found2 + 1 << "\n";
            return;
        }
    }
    cout << "NO\n";
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