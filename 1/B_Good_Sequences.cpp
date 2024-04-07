#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> divisor(100005);
vector<int> ans(100005, 0), dp(100005, 0);
void makediv()
{
    for(int i=2; i<=100002; i++)
        for(int j=i; j<=100002; j+=i)
            divisor[j].push_back(i);
    return;
}
void solve()
{
    cin >> n;
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    for(auto i: v)
    {
        int mx = 0;
        for(int j=0; j<divisor[i].size() && divisor[i][j]<=i; j++)
            mx = max(mx, dp[divisor[i][j]]);
        ans[i] = mx+1;
        for(int j=0; j<divisor[i].size() && divisor[i][j]<=i; j++)
            dp[divisor[i][j]] = max(dp[divisor[i][j]], ans[i]);
    }
    int mx = 0;
    for(auto i: v)
        mx = max(mx, ans[i]);
    cout << mx << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    makediv();
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