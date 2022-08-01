#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s, tm, mn;
    cin >> s;
    set<string> st;
    vector<int>v;
    int n = s.size();
    for(int i = 0; i<n; i++)
    {
        tm = "";
        for(int j = i; j<n; j++)
        {
            tm += s[j];
            mn = tm;
            int l = tm.size();
            for(int i = 1; i<=l; i++)
            {
                string nw = tm.substr(l-i, i)+tm.substr(0, l-i);
                // cout << nw << "\n";
                mn = min(mn, nw);
            }
            // cout << mn << "\n\n";
            st.insert(mn);
        }
    }
    cout << st.size() << "\n";
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