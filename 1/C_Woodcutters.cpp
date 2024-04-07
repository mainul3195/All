#include<bits/stdc++.h>
using namespace std;
struct pr {long long a, b; bool operator < (const pr &x)const {return a<x.a || (a==x.a && b<x.b);}};
vector<pr>tr;
vector<vector<long long>> dp;
long long n;
long long okdone(long long i = 1, long long prev = 0)
{
    // cout << i << " " << n << " " << prev << "\n";
    if(i==n+1) return 0;
    if(~dp[i][prev]) return dp[i][prev];
    long long a1 = 0, a2 = 0, a3 = 0;
    a1 = okdone(i+1, 0);
    if(i==n || (i<n && tr[i].a+tr[i].b<tr[i+1].a)) a2 = 1+okdone(i+1, 2);
    long long avail = tr[i].a-tr[i-1].a-1;
    if(prev == 2) avail -= tr[i-1].b;
    if(avail>=tr[i].b) a3 = 1+okdone(i+1, 1);
    // cout << a1 << " " << a2 << " " << a3 << "\n";
    return dp[i][prev] = max({a1, a2, a3});
}
void solve()
{
    cin >> n;
    tr = vector<pr>(n+1);
    dp = vector<vector<long long>> (n+1, vector<long long> (3, -1));
    tr[0] = {-10000000000, 0};
    for(long long i=1; i<=n; i++)
        cin >> tr[i].a >> tr[i].b;
    cout << okdone() << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t = 1;
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