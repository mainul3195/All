#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int h, w, rb, cb, rd, cd;
    cin >> h >> w >> rb >> cb >> rd >> cd;
    int ansr, ansc;
    if(rd>=rb)
        ansr = rd-rb;
    else ansr = 2*h - rb - rd;
    if(cd>=cb)
        ansc = cd-cb;
    else ansc = 2*w - cb - cd;
    cout << min(ansr, ansc) << "\n";
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