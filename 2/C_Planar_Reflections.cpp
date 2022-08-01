#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector<vector<vector<long long>>> dp;
int n, k;
long long okdone(int dir = 1, int i = 0, long long x = k)
{
    if(i<0 || i==n || x==1)
    {
        // cout << dir << " " << i << " " << x << "\n";
        return 1;
    }
    if(~dp[dir][i][x])
        return dp[dir][i][x];
    return dp[dir][i][x] = (okdone(!dir, i + (dir ? -1 : 1), x - 1) + okdone(dir, i + (!dir ? -1 : 1), x)) % mod;
}
void solve()
{
    cin >> n >> k;
    dp = vector<vector<vector<long long>>>(2, vector<vector<long long>>(n + 1, vector<long long>(k + 1, -1)));
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