#include<bits/stdc++.h>
using namespace std;
long long sd(long long n)
{
    for (long long i = 3; i * i <= n; i+=2)
        if(!(n%i))
            return i;
    return n;
}
void solve()
{
    long long n, k;
    cin >> n >> k;
    if(n%2)
        cout << n + (k - 1) * 2 + sd(n) << "\n";
    else
        cout << n + k * 2 << "\n";
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