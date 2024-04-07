#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
vector<int> dp(600000, -1);
int n;
int fibo(int n)
{
    if(n==1 || n==2) return 1;
    if(~dp[n]) return dp[n];
    return dp[n] = (fibo(n-1)+fibo(n-2))%mod;
}
void solve()
{
    cin >> n;
    cout << fibo(n) << "\n";
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