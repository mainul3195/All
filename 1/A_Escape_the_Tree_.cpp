#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int h;
    cin >> h;
    cout << "2 1 " << h << "\n";
    int leaf, dis;
    cin >> leaf;
    for(int i =0; i<h; i++)
    {
        cout << "1 " << leaf << "\n";
        cin >> dis;
        if(!dis)
        {
            cout << "3 " << leaf << "\n";
            int ok;
            cin >> ok;
            break;
        }
        cout << "2 " << leaf << " " << dis << "\n";
        cin >> leaf;
    }
    return;
}
int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
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