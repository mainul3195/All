#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n), dif(n);
    for(auto &i: v)
        cin >> i;

    for(int i = 0; i<n; i++)
        dif[i] = v[i] - min(i, n-i-1);
    // for(auto i: dif)
    //     cout << i << " ";
    //     cout << "\n";
    long long mx = 0;
    for(auto &i: dif)
    {
        if(i<0) i = 0;
        mx = max(mx, i);
    }
    // cout << mx << "\n";
    vector<long long> count(mx+2, 0);
    for(auto i: dif)
        count[i]++;
    long long ans = n;
    for(int i = 1; i<=mx; i++)
        ans = min(ans, n-count[i]);
    cout << ans << "\n";
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