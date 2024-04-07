#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &i: a)
        cin >> i;
    for(auto &i: b)
        cin >> i;
    int am = 2147483647, bm = 2147483647;
    for(auto i: a)
        am = min(am, i);
    for(auto i: b)
        bm =  min(bm, i);
    long long ans = 0;
    for(int i=0; i<n; i++)
    {
        int t = min(a[i]-am, b[i]-bm);
        ans += a[i]+b[i]-am-bm-t;
    }
    cout << ans << "\n";
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