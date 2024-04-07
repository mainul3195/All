#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int sum =0;
    for(auto &i: v) 
    {
        cin >> i;
        sum+=i;
    }
    sort(v.begin(),v.end());
    if(!(sum%2) && (!(sum%4) || (sum%4 && v[0]==1))) cout << "YES\n";
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