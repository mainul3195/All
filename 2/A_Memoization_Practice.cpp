#include<bits/stdc++.h>
using namespace std;
vector<int> dp(200, -1);
int okdone(int n)
{
    if(n>100) return n-10;
    if(~dp[n]) return dp[n];
    return dp[n] = okdone(okdone(n+11));
}

void solve()
{
    int n;
    while(cin >> n && n)
        cout << "f91("<< n << ") = " << okdone(n) << "\n";
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