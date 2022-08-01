#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y ;
    if((x+y)&1)
        cout << "-1 -1\n";
    else
    {
        int mid = ((x+y)>>1), i, j;
        for(int i=0; i<=x; i++)
            for(int j=0; j<=y; j++)
                if((i+j)==mid)
                {
                    cout << i << " " << j <<"\n";
                    return;
                }
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
inf
linf
*/