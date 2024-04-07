#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> v(n - 2);
    for (auto &i : v)
        cin >> i;
    bool found = 0;
    for (int i = 0; i < n - 2; i++)
    {
        if (!i)
            cout << v[i][0];
        else
        {
            if (v[i][0] == v[i - 1][1])
                cout << v[i][0];
            else
            {
                found = 1;
                cout << v[i - 1][1] << v[i][0];
            }
        }
    }
    cout << v[n - 3][1];
    if (!found)
        cout << "a";
    cout << "\n";
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