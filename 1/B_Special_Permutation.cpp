#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    v[0] = a;
    v[n-1] = b;
    int s = n;
    for(int i=1; i<n-1; i++)
    {
        if(s==a || s==b) s--;
        if(s==a || s==b) s--;
        v[i] = s--;
    }
    int mn = 1000000000, mx = 0;
    for(int i=0; i<n/2; i++)
        mn = min(v[i], mn);
    for(int i=n/2; i<n; i++)
        mx = max(mx, v[i]);
    if(mn==a && mx == b)
    {
        for(auto i: v)
            cout << i << " ";
            cout << "\n";
    }
    else cout << "-1\n";
    
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