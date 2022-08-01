#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    if(n==1)
    {
        cout << "0\n";
        return;
    }
    int mx = 0;
    for(int d = -200; d<=200; d++)
        for(int m = 1; m<=70; m++)
            for(int start = 0; start<n; start++)
            {
                int prev = -1;
                int count = 0;
                int elem = 0;
                for(int i = start; i<n; i+=m, elem++)
                    if(v[i] == v[start] + elem*d)
                        count ++;
                mx = max(mx, count);
                // cout << "\t" << start << " " << count << "\n";
            }
    cout << n-mx << "\n";
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