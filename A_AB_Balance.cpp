#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    if(s[0]!=s[s.size()-1])
        s[0] = s[s.size()-1];
    cout << s << "\n";
    
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