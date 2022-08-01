#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<long long> f(n);
    for(auto &i: f)
        i = 2147483647;
    vector<int> ind(k);
    for(auto &i: ind)
        cin >> i;
    for(int i=0; i<k; i++)
    {
        int j;
        cin >> j;
        f[ind[i]-1] = j;
    }
    vector<long long> l(n, 0), r(n, 0);
    long long p = 2147483647;
    for(int i=0; i<n; i++)
        p = l[i] = min(p+1, f[i]);
    p = 2147483647;
    for(int i=n-1; i>=0; i--)
        p = r[i] = min(p+1, f[i]);
    
    for(int i=0; i<n; i++)
        f[i] = min(l[i], r[i]);
    for(auto i: f)
        cout << i << " ";
    cout << "\n";
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