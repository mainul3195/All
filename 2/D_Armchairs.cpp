#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> s, e;
vector<vector<int>> dp;
long long  okdone(int i = 0, int j = 0)
{
    if(i==s.size() && j == e.size())
        return 0;
    if(i==s.size() || j == e.size())
        return 2147483647;
    if(~dp[i][j])
        return dp[i][j];
    return dp[i][j] = min(abs(s[i] - e[j]) + okdone(i + 1, j + 1), okdone(i + 1, j));
}

void solve()
{
    cin >> n;
    s = vector<int>();
    e = vector<int>();
    dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        if(j)
            s.push_back(i);
        else
            e.push_back(i);
    }
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