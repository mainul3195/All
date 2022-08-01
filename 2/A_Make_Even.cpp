#include<bits/stdc++.h>
using namespace std;
int calc(string &s)
{
    if((s[s.size()-1]-'0')%2 == 0)
        return 0;
    if((s[0]-'0')%2 == 0)
        return 1;
    for(auto i: s)
        if((i-'0')%2 == 0)
            return 2;
    return -1;
}
void solve()
{
    string s;
    cin >> s;
    cout << calc(s) << "\n";
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