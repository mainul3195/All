#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    getline(cin , s);
    for(auto &i: s) i=toupper(i);
    char last;
    for(auto c: s)
        if(c>='A'&&c<='Z') last = c;
    if(last == 'A' || last == 'E' || last == 'O' || last == 'U' || last == 'Y') cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
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
*/