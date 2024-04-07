#include<bits/stdc++.h>
using namespace std;
vector<int>pw;
int findzero(int x, int pos)
{
    x++;
    int ans = 0;
    ans += x/pw[pos];
    ans *= pw[pos-1];
    int r = x%pw[pos];
    ans += min(r, pw[pos-1]);
    return ans;
}
void solve()
{
    int l, r;
    cin >> l >> r;
    int ans = 110011000;
    for(int i = 0; pw[i]<=r; i++)
        ans = min(ans, findzero(r, i+1)-findzero(l-1, i+1));
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ml = 1;
    for(; ml<10000000; ml<<=1)
        pw.push_back(ml);
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