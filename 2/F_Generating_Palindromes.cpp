#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
string s;
int okdone(int i, int j)
{
    if(i>=j) return 0;
    if(~dp[i][j]) return dp[i][j];
    return dp[i][j] = (s[i]==s[j] ? okdone(i+1, j-1) : 1+min(okdone(i+1, j), okdone(i, j-1)));
}
void solve()
{
    cin >> s;
    dp = vector<vector<int>> (s.size()+2, vector<int> (s.size()+2, -1));
    cout << okdone(0, s.size()-1) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, tc = 0;
    cin >> t;
    while(t--)
    {
        cout << "Case " <<  ++tc << ": ";
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