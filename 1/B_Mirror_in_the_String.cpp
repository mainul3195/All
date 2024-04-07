#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if(n==1 || s[0]<=s[1])
    {
        cout << s[0]<< s[0] << "\n";
        return;
    }
    int i = 2;
    while(i<s.size() && s[i-1]>=s[i]) i++;
    cout << s.substr(0, i);
    for(int j = i-1; j>=0; j--)
        cout << s[j];
        cout << "\n";
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