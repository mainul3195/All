#include<bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> v(7);
    for(auto &i: v)
        cin >> i;
    sort(v.begin(), v.end());
    cout << v[0] << " " << v[1] << " " << v[6] - v[1] - v[0] << "\n";
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