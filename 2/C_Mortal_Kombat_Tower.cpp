#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> boss;
vector<vector<int>> dp;
int okdone(int myfriend = 1, int i = 0)
{
    if(i==n) return 0;
    if(~dp[i][myfriend]) return dp[i][myfriend];
    int a =okdone(!myfriend , i+1)+(myfriend&&boss[i]);
    if(i<n-1) a = min(a, okdone(!myfriend, i+2) + (myfriend && boss[i]) + (myfriend && boss[i+1]));
    return dp[i][myfriend] = a ;
}
void solve()
{
    cin >> n;
    boss = vector<int> (n);
    dp = vector<vector<int>> (n+2, vector<int> (3, -1));
    for(auto &i: boss) cin >> i;
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