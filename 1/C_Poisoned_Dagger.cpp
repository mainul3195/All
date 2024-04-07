#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int n;
ll k;
vector<ll>power;
bool possible(ll x)
{
    ll tot = x;
    for(int i = 1; i<power.size(); i++)
        tot += min(x, power[i]-power[i-1]);
    if(tot>=k) return 1;
    return 0;
}
void solve()
{
    cin >> n >> k;
    power = vector<ll> (n);
    for(auto &i: power)
        cin >> i;
    ll l = 1, r = 1000000000000000000, mid, ans = 1000000000000000000;
    while(l<=r)
    {
        mid = (l+r)>>1;
        if(possible(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << "\n";
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