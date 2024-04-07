#include<bits/stdc++.h>
using namespace std;
struct pr {long long a, b; bool operator < (const pr &x)const {return a<x.a || (a==x.a && b<x.b);}};
int n, tot, w;
vector<pr> coins;
vector<long long> dp;
void solve()
{
    tot = 0;
    cin >> n >> w;
    coins = vector<pr>(n);
    for(auto &i: coins) {cin >> i.a >> i.b;tot+=i.b;}
    dp = vector<long long> (tot+1, 2147483647);
    dp[0] = 0;
    for(int i=0; i<n; i++)
        for(int j = tot; j>=coins[i].b; j--)
            dp[j]  = min(dp[j], coins[i].a + dp[j-coins[i].b]);
    for(int i= tot; i>=0; i--)
        if(dp[i]<=w)
        {
            cout << i << "\n";
            return;
        }
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