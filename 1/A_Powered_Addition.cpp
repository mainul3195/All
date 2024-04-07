#include <bits/stdc++.h>
using namespace std;
int calc(int a, int b)
{
    int count = 0;
    int d = a - b;
    while(d)
    {
        d >>= 1;
        count++;
    }
    return count;
}
void solve()
{
    int n;
    cin >> n;
    int mx, ans = 0;
    cin >> mx;
    for (int i = 1; i < n; i++)
    {
        int j;
        cin >> j;
        if (j > mx)
            mx = j;
        else
            ans = max(ans, calc(mx, j));
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