#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<int>v;
    for(int i=0; i<n; i++)
    {
        int j;
        cin >> j;
        if(j>=l && j<=r) v.push_back(j);
    }
    sort(v.begin(), v.end());
    int count = 0;
    for(int i= 0; i<v.size(); i++)
        if(v[i]<=k)
        {
            count ++;
            k-=v[i];
        }
    cout << count << "\n";
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