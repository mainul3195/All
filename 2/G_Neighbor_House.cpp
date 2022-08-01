#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> col, dp;
int n;
int okdone(int i = 1, int prev = 3)
{
    if(i==n+1) return 0;
    if(~dp[i][prev]) return dp[i][prev];
    int mn = 100000000;
    for(int j=0; j<3; j++)
        if(j!=prev)
            mn = min(mn, okdone(i+1, j)+col[i][j]);
    return dp[i][prev] = mn;
}
void solve()
{
    cin >> n;
    col = vector<vector<int>> (n+1, vector<int> (3, -1));
    dp = vector<vector<int>> (n+1, vector<int> (4, -1));
    for(int i=1; i<=n; i++)
        for(int j=0; j<3; j++)
            cin >> col[i][j];
    cout << okdone() << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, tc = 0;
    cin >> t;
    while(t--)
    {
        cout << "Case " <<  ++tc << ": ";
        solve(); 
    }
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