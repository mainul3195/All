#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> v;
vector<vector<int>> dp;
int okdone(int i = 0, int xr = k)
{
    if(i==n) return xr;
    if(~dp[i][xr]) return dp[i][xr];
    return dp[i][xr] = max(okdone(i+1, xr), okdone(i+1, xr^v[i]));
}
void solve()
{
    cin >> n >> k;
    v = vector<int> (n);
    for(auto &i: v)
        cin >> i;
    dp = vector<vector<int>> (n+1, vector<int> (1025, -1));

    cout << okdone() << "\n";

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