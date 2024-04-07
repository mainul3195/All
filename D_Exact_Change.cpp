#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int ans = 2147483647;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
        {
            int three = 0;
            bool possible = 1;
            for (auto c : v)
            {
                bool ok = 0;
                int mn = 2000000000;
                for (int one = 0; one <= i; one++)
                    for (int two = 0; two <= j; two++)
                    {
                        int rem = c - one - 2 * two;
                        if (!(rem % 3) && rem >= 0)
                            mn = min(mn, rem / 3), ok = 1;
                    }
                if (!ok)
                {
                    possible = 0;
                    break;
                }
                three = max(three, mn);
            }
            if (possible)
                ans = min(ans, i + j + three);
        }
    cout << ans << "\n";
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