#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<long long> dp(100005);
    for(auto &i: dp)
        i = 2147483647;
    dp[0] = 0;
    while(n--)
    {
        int wt, v;
        cin >> wt >> v;
        for(int i=100000; i>=v; i--)
            dp[i] = min(dp[i], dp[i-v]+wt);
    }
    for(int i=100000; i>=0; i--)
        if(dp[i]<=w)
        {
            cout << i << "\n";
            return;
        }
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