#include<bits/stdc++.h>
using namespace std;
bool possible(long long a, long long b, long long x)
{
    if(!b) return a==x;
    if(x<=a && x%b == a%b)
        return 1;
    return possible(b, a%b, x);
}
void solve()
{
    long long a, b, x;
    cin >> a >> b >> x;
    if(a<b)
        swap(a, b);
    if(possible(a, b, x))
        cout << "YES\n";
    else cout << "NO\n";
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