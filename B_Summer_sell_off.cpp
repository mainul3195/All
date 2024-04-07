#include<bits/stdc++.h>
using namespace std;
struct pr {
    long long a, b; 
    bool operator < (const pr &x)const {
    return (a<b && x.a>=x.b)||(a<b && x.a<x.b && ((min(2*a, b)-a)>(min(2*x.a, x.b)-x.a)));
    }
};

void solve()
{
    int n, l;
    cin >> n >> l;
    vector<pr>item(n);
    for(auto &i: item)
        cin >> i.a >> i.b;
    sort(item.begin(), item.end());
    int lim = min(l, n);
    long long ans = 0;
    for(int i=0; i<lim; i++)
        ans += min(2*item[i].a, item[i].b);
    for(int i=lim; i<n; i++)
        ans += min(item[i].a, item[i].b);
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