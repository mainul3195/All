#include<bits/stdc++.h>
using namespace std;
int k;
vector<int> v(12);
void solve()
{
    cin >> k;
    for(auto &i: v)
        cin >> i;
    sort(v.begin(), v.end());
    int tot = 0, ans = 0;
    for(int i = 11; i>=0; i--)
    {
        tot += 
    }
    cout << (ans==14?-1:ans) << "\n";
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