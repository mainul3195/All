#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<double>> dp;
vector<double>prob;
void solve()
{
    cin >> n;
    dp = vector<vector<double>>(n+3, vector<double>(n+2, 0));
    dp[0][1] = 1;
    prob = vector<double>(n);
    for(auto &i: prob) cin >> i;
    for(int i=1; i<=n; i++)
        for(int j=0; j<=i; j++)
            dp[i][j+1] = dp[i-1][j]*prob[i-1] + dp[i-1][j+1]*(1-prob[i-1]);
    double ans = 0;
    for(int i=n/2+2; i<=n+1; i++)
        ans += dp[n][i];
    cout << fixed << setprecision(12) << ans << "\n";
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