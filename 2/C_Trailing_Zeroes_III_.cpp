#include <bits/stdc++.h>
using namespace std;
int trailingZero(long long n)
{
    int count = 0;
    while (n)
    {
        count += n / 5;
        n /= 5;
    }
    return count;
}
void solve()
{
    int q;
    cin >> q;
    long long l = 5, r = 2000000000, mid, ans = -1;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        int tmp = trailingZero(mid);
        if (tmp < q)
            l = mid + 1;
        else
        {
            if (tmp == q)
                ans = mid;
            r = mid - 1;
        }
    }
    if (ans == -1)
        cout << "impossible\n";
    else
        cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
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