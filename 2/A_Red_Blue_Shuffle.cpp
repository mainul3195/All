#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string r, b;
    cin >> r >> b;
    int rc = 0, bc = 0;
    for (int i = 0; i < n; i++)
    {
        if(r[i]>b[i])
            rc++;
        else if(r[i]<b[i])
            bc++;
    }
    cout << (rc == bc ? "EQUAL\n" : (rc > bc ? "RED\n" : "BLUE\n"));
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