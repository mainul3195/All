#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    int a[27] = {};
    for (auto i : s)
        a[i - 'a']++;
    sort(s.begin(), s.end());
    if (a[0] && a[1] && a[2] && t == "abc")
    {
        while(a[0]--)
            cout << "a";
        while(a[2]--)
            cout << "c";
        while(a[1]--)
            cout << "b";
        for (int i = 3; i < 26; i++)
            while(a[i]--)
                cout << (char)('a' + i);
            cout << "\n";
    }
    else
        cout << s << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
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