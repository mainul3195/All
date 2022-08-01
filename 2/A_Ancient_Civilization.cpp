#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int mul = 1, answer = 0;
    for (int j = 0; j < l; j++)
    {
        int no0 = 0, no1 = 0;
        for (auto &i : v)
        {
            if (i & 1)
                no1++;
            else
                no0++;
            i >>= 1;
        }
        if (no1 > no0)
            answer += mul;
        mul <<= 1;
    }
    cout << answer << "\n";
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