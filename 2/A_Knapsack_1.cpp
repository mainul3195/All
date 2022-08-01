#include<bits/stdc++.h>
using namespace std;
struct pr {long long a, b; bool operator < (const pr &x)const {return a<x.a || (a==x.a && b<x.b);}};
long long n, w;
vector<pr>item;
vector<vector<long long>> dp;
long long okdone(int i = 0, long long rem = w)
{
    if(i==n || !rem) return 0;
    if(~dp[i][rem]) return dp[i][rem];
    return dp[i][rem] = max(okdone(i+1, rem), (rem>=item[i].a? okdone(i+1, rem-item[i].a)+item[i].b : 0));
}
void solve()
{
    cin >> n >> w;
    dp = vector<vector<long long>> (n+1, vector<long long> (w+1, -1));
    item = vector<pr>(n);
    for(auto &i: item)cin >> i.a >> i.b;
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