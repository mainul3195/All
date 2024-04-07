#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
vector<long long> val, noc;
vector<vector<long long>> dp;
long long n, k;
long long done(long long i=0, long long sum = k)
{
    if(!sum) return 1;
    if(i==n || sum<0) return 0;
    if(~dp[i][sum]) return dp[i][sum];
    long long ans = 0;
    for(long long j=0; j<=noc[i]; j++)
        ans += done(i+1, sum - j*val[i]);
    ans %= mod;
    return dp[i][sum] = ans;
}
void solve()
{
    cin >> n >> k;
    dp = vector<vector<long long>> (n+2, vector<long long> (k+2, -1));
    val = vector<long long> (n);
    noc = vector<long long> (n);
    for(auto &i: val)cin >> i;
    for(auto &i: noc)cin >> i;
    cout << done() << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t = 1, tc =1;
    cin >> t;
    while(t--)
    {
        cout << "Case " << tc++ << ": ";
        solve(); 
    }
    return 0;
}

/*
gcd
lcm
modfact
fact
pfsingle    && hoyeche[j-val[i]][i]<noc[i]
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