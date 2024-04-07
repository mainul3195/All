#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
void solve()
{
    long long n, k;
    cin >> n >> k;
    v = vector<long long>(n);
    for(auto &i: v)
        cin >> i;
    for(auto &i: v)
        i = pow(10, i)+.05;
    sort(v.begin(), v.end());
    long long ans=0;
    long long r = k+1;
    for(int i=1; i<n; i++)    
    {
        long long t = min(r, v[i]/v[i-1] - 1);
        ans += v[i-1]*t;
        r-=t;
    }
    ans += r*v[n-1];
    cout << ans << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t = 1;
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
*/