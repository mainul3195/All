#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<vector<int>> dp;
int okdone(int i=0, int j = 3)
{
    if(i==n) return 0;
    if(~dp[i][j]) return dp[i][j];
    int ans = okdone(i+1, 0) + 1;
    if(a[i]==1 && j!=1) ans = min(ans, okdone(i+1, 1));
    else if(a[i]==2 && j!=2) ans = min(ans, okdone(i+1, 2));
    else if(a[i]==3)
    {
        if(j!=1) ans = min(ans, okdone(i+1, 1));
        if(j!=2) ans = min(ans, okdone(i+1, 2));
    }
    return dp[i][j] = ans;
}
void solve()
{
    cin >> n;
    a = vector<int> (n);
    dp = vector<vector<int>> (n+1, vector<int> (4, -1));
    for(auto &i: a)  cin >> i;
    cout << okdone() << "\n";
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