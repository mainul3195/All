#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int h, w;
    cin >> h >> w;
    if(h==1 && w==1)
        cout << "0\n";
    else if(h==1 || w==1)
        cout << "1\n";
    else cout << "2\n";
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