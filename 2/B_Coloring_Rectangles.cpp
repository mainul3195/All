#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int h, w;
    cin >> h >> w;
    if(w>h)
        swap(h, w);
    long long ans = 0;
    while(h && w && (h>2 || w>2))
    {
        ans += (h/3)*w;
        h %= 3;
        if(w>h) swap(h, w);
    }
    if(h && w)
    {
        if(h==2 && w==2) ans += 2;
        else ans++;
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