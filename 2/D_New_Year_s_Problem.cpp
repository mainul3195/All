#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>>inf;
bool possible(int x)
{
    vector<bool>done(n, 0);
    bool dbl = 0;
    for(int i = 0; i<m; i++)
    {
        int cnt = 0;
        for(int j = 0; j<n; j++)
            if(inf[i][j]>=x)
            {
                cnt++;
                done[j] = 1;
            }
        if(cnt>1) dbl = 1;
    }
    if(!dbl && n>1) return 0;
    dbl = 1;
    for(auto i: done)
        dbl &= i;
    return dbl;
}
void solve()
{
    cin >> m >> n;
    inf = vector<vector<int>>(m, vector<int> (n));
    int mx = 0;
    for(auto &i: inf)
        for(auto &j: i)
        {
            cin >> j;
            mx = max(mx, j);
        }
    int l = 1, r = mx, mid, ans = 1;
    while(l<=r)
    {
        mid = (l+r)>>1;
        if(possible(mid))
        {
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
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