#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (!f)
        {
            int j;
            for (j = 0; i + j < n && j < k; j++)
                cout << "a";
            i += j;
            f++;
        }
        else if (f == 1)
        {
            int j;
            for (j = 0; i + j < n && j < k; j++)
                cout << "b";
            i += j;
            f++;
        }
        else
        {
            int j;
            for (j = 0; i + j < n && j < k; j++)
                cout << "c";
            i += j;
            f = 0;
        }
        i--;
        // cout << i << " " << f << "\n";
    }
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