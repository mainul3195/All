#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int mx = 0;
    for(auto &i: v)
    {
        cin >> i;
        mx = max(mx, i);
    }
    int lm = 0;
    int ans = 0;
    for(int i = n-1; i>=0; i--)
    {
        if(v[i]==mx)
            break;
        if(v[i]>lm)
        {
            ans ++ ;
            lm = v[i];
        }
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