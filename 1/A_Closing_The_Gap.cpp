#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int tot = 0;
    int a;
    for(int i= 0; i<n; i++)
    {
        cin  >> a;
        tot += a;
    }
    cout << (int)(tot%n!=0) << "\n";
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