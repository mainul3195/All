#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(3, 0), b(3);
    while(n--)
    {
        for(auto &i: b)
            cin >> i;
        for(int i=0; i<3; i++)
        {
            int mx = -1000000000;
            for(int j=0; j<3; j++)
                if(i!=j) mx = max(mx, a[j]);
            b[i]+=mx;
        }
        a = b;
    }
    cout << max({a[0], a[1], a[2]});
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
*/