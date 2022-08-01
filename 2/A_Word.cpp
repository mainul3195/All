#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int up = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            up++;
    }
    int low = s.size() - up;
    if (up > low)
    {
        for (int i = 0; i < s.size(); i++)
        {
            cout << (char)toupper(s[i]);
        }
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            cout << (char)tolower(s[i]);
        }
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
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