#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<long long>> dp;
long long okdone(int i = 1, int rem = n)
{
    if(!rem)
        return 1;
    if(i==22)
        return 0;
    if(~dp[i][rem])
        return dp[i][rem];
    long long tot = 0;
    for (int j = 0; j * i * i *i <= rem; j++)
        tot += okdone(i + 1, rem - j * i * i * i);
    return dp[i][rem] = tot;
}
void solve()
{
    while(cin >> n)
        cout << okdone() << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    dp = vector<vector<long long>>(23, vector<long long>(10004, -1));
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