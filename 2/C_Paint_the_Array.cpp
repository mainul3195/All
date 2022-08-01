#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for(auto &i: v)
        cin >> i;
    long long gcd = 0;
    for (int i = 0; i < n; i+=2)
        gcd = __gcd(gcd, v[i]);
    if(gcd>1)
    {
        bool ok = 1;
        for (int i = 1; i < n; i+=2)
            if(!(v[i]%gcd))
            {
                ok = 0;
                break;
            }
        if(ok)
        {
            cout << gcd << "\n";
            return;
        }
    }
    
    gcd = 0;
    for (int i = 1; i < n; i+=2)
        gcd = __gcd(gcd, v[i]);
    if(gcd>1)
    {
        bool ok = 1;
        for (int i = 0; i < n; i+=2)
            if(!(v[i]%gcd))
            {
                ok = 0;
                break;
            }
        if(ok)
        {
            cout << gcd << "\n";
            return;
        }
    }
    cout << 0 << "\n";
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