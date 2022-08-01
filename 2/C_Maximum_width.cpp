#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    vector<int> l(m), r(m);
    int s = 0;
    for(int i=0; i<m; i++)
    {
        while(a[s++]!=b[i]);
        l[i] = s-1;
    }
    s = n-1;
    for(int i = m-1; i>=0; i--)
    {
        while(a[s--]!=b[i]);
        r[i] = s+1;
    }
    int ans = 0;
    for(int i=0; i<m-1; i++)
        ans = max(ans, r[i+1]-l[i]);
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