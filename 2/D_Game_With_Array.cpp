#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, s;
    cin >> n >> s;
    if(s>=2*n)
    {
        cout << "YES\n";
        for (int i = 1; i < n; i++)
        {
            cout << "2 ";
            s -= 2;
        }
        cout << s << "\n1";
    }
    else
        cout << "NO\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
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