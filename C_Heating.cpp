#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    while(n--)
    {
        long long c, sum, d, r;
        cin >> c >> sum;
        d = sum/c;
        r = sum%c;
        cout << d*d*(c-r) + r*(d+1)*(d+1) << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
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