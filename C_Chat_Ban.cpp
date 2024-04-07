#include<bits/stdc++.h>
using namespace std;
long long k, x;
bool possible(long long ms)
{
    long long a = min(ms, k);
    long long tot = a*(a+1)/2;
    a = min(k-1, ms-a);
    tot += a*k - a*(a+1)/2;
    if(tot<x) return 1;
    return 0;
}
void solve()
{
    cin >> k >> x;
    long long  l = 0, r = x, mid, ans = 0;
    while(l<=r)
    {
        mid = (l+r)>>1;
        if(possible(mid))
        {
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << min(2*k-1, ans +1) << "\n";
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