#include<bits/stdc++.h>
using namespace std;
int n;
vector<long long>v;
bool possible(int x)
{
    // cout << x << "\n";
    vector<long long>tmp = v;
    for(int i = n-1; i>=0; i--)
    {
    // if(x==16)
    //         for(auto j: tmp)
    //         cout << j << " ";
    //         cout << "\n";
        if(tmp[i]<x) return 0 ;
        long long extra = min(v[i],tmp[i]-x)/3;
        // cout << "extra -> " << extra << "\n";
        if(i>=2)
        {
            tmp[i]-=3*extra;
            tmp[i-1]+=extra;
            tmp[i-2]+=2*extra;
        }

    }

    return 1;
}
void solve()
{
    cin >> n;
    v = vector<long long> (n);
    long long mx = 0, mn = 2000000000;
    for(auto &i: v)
        cin >> i, mx = max(mx, i), mn = min(mn,  i);
    int l = mn, r = mx, ans = mn, mid;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(possible(mid))
        {
            ans = mid;
            l = mid+1;
        }
        else r = mid - 1;
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