#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    bool ok = 0;
    while(n!=1)
    {
        if(n&1)
        {
            ok = 1;
            break;
        }
        n >>= 1;
    }
    if(ok)
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
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