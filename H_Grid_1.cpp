#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int h, w;
int fa(int i, int j, vector<string> &grid, vector<vector<int>> &ans)
{
    if(i<h && j<w && (grid[i][j]=='.')) return ans[i][j];
    return 0;
}
void solve()
{
    cin >> h >> w;
    vector<string>grid(h);
    for(auto &i: grid) cin >> i;
    vector<vector<int>> ans(h, vector<int> (w, 0));
    ans[h-1][w-1] = 1;
    for(int i=h-1; i>=0; i--)
        for(int j= w-1; j>=0; j--)
            ans[i][j] = (ans[i][j] + fa(i+1, j, grid, ans)+fa(i, j+1, grid, ans))%mod;
    cout << ans[0][0] << "\n";
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