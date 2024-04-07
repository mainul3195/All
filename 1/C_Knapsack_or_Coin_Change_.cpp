#include<bits/stdc++.h>
using namespace std;
int n, tot;
vector<int> coins;
vector<vector<int>> dp;
int okdone(int i = 0, int done = 0)
{
    if(i==n) return abs(tot - 2*done);
    if(~dp[i][done]) return dp[i][done];
    int a1 = okdone(i+1, done);
    int a2 = okdone(i+1, done+coins[i]);
    return dp[i][done] = min(a1, a2);
}
void solve()
{
    tot = 0;
    cin >> n;
    coins = vector<int> (n);
    for(auto &i: coins) {cin >> i;tot+=i;}
    dp = vector<vector<int>> (n+1, vector<int> (tot+1, -1));
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