#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for(auto &i: v) cin >> i;
    long long mul = 1;
    for(auto &i: v)
        while(!(i%2))
        {
            i>>=1;
            mul<<=1;
        }
    sort(v.begin(), v.end());
    v[n-1] *= mul;
    long long sum = 0;
    for(auto i: v)
        sum += i;
    cout << sum << "\n";
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