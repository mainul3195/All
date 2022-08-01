#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for(auto &i: v)
        cin >> i;
    sort(v.begin(), v.end());
    int ans = 0, i, j;
    for(i = n-1, j = n-k-1; i+k>=n; i--, j--)
    {
        ans += v[j]/v[i];
        v[i] = v[j] = 0;
    }
    for(auto i: v)
        ans += i;
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