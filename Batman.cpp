#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> dp;
string a, b, c;
int dop(int i=0, int j=0, int k=0)
{
    if(i==a.size()||j==b.size()||k==c.size()) return 0;
    if(~dp[i][j][k]) return dp[i][j][k];
    int r1 = (a[i]==b[j] && b[j]==c[k])? dop(i+1, j+1, k+1)+1: 0;
    int r2 = dop(i+1, j, k);
    int r3 = dop(i, j+1, k);
    int r4 = dop(i, j, k+1);
    return dp[i][j][k] = max({r1, r2, r3, r4});
}
void solve()
{
    cin >> a >> b >> c;
    dp = vector<vector<vector<int>>> (a.size()+2, vector<vector<int>> (b.size()+2, vector<int> (c.size()+2, -1)));
    cout << dop() << "\n";
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