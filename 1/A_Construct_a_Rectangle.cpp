#include<bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> v(3);
    for(auto &i: v)
        cin >> i;
    sort(v.begin(), v.end());
    if(v[0]+v[1]==v[2] || ( v[0] == v[1] && !(v[2]%2)) || ( v[2] == v[1] && !(v[0]%2)))
        cout << "YES\n";
    else cout << "NO\n";
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