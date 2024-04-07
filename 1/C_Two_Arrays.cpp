#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &i: a)
        cin >> i;
    for(auto &i: b)
        cin >> i;
    bool ok = 1;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=0; ok && i<n; i++)
    {
        bool hoise = 0;
        for(int j=0; j<n; j++)
            if(a[i]==b[j])
            {
                a[i] = b[j] = 1000;
                hoise = 1;
                break;
            }
        for(int j=0; !hoise && j<n; j++)
            if(a[i]+1==b[j])
            {
                a[i] = b[j] = 1000;
                hoise = 1;
                break;
            }
        if(!hoise) ok = !ok;
    }
    cout << (ok? "YES\n": "NO\n");
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