#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if(k>(n-1)/2)
        cout <<  "-1\n";
    else
    {
        int s=1, tp = n;
        for(int j=0; j<k; j++)
            cout << s++ << " " << tp-- << " ";
        for(int j=tp; j>=s; j--)
            cout << j << " ";
        cout << "\n";
    }
    
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
*/