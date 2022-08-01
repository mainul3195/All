#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> h, dp;
int okdone(int i = 0)
{
    if(i==n-1) return 0;
    if(~dp[i]) return dp[i];
    int a1 =100000000, a2 = 100000000;
    if(i<n-1) a1 = okdone(i+1) + abs(h[i+1]-h[i]);
    if(i<n-2) a2 = okdone(i+2) + abs(h[i+2]-h[i]);
    return dp[i] = min(a1, a2);
}
void solve()
{
    cin >> n;
    h = vector<int> (n);
    dp = vector<int> (n, -1);
    for(auto &i: h) cin >> i;
    cout << okdone() << "\n";
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