#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    long long one = n / 2;
    int rem = n % 2;
    if (rem)
        one--;
    if (rem)
        cout << "7";
    for (int i = 0; i < one; i++)
        cout << "1";

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