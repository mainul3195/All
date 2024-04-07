#include<bits/stdc++.h>
using namespace std;
vector<long long> fibo(46);

void solve()
{
    int n;
    cin >> n;
    cout << fibo[n] << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fibo[1] = 2;
    fibo[2] = 2;
    for(int i=3; i<46; i++)
        fibo[i] = fibo[i-1]+fibo[i-2];
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