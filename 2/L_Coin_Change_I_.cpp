#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
vector<long long> a, c;
vector<vector<long long>> dp;
int n, k;
long long okdone(int i = 0, int rem = k)
{
    if(!rem)
        return 1;
    if(i==n)
        return 0;
    if(~dp[i][rem])
        return dp[i][rem];
    long long  tot = 0;
    for (int j = 0; j <= c[i] && j*a[i]<=rem; j++)
        tot += okdone(i + 1, rem - j * a[i]);
    tot %= mod;
    return dp[i][rem] = tot;
}
void solve()
{
    cin >> n >> k;
    a = vector<long long>(n);
    c = vector<long long>(n);
    for(auto &i: a)
        cin >> i;
    for(auto &i: c)
        cin >> i;
    dp = vector<vector<long long>>(n + 1, vector<long long>(k + 1, -1));
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
        cout << "Case " << ++tc << ": ";
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