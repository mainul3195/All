#include <bits/stdc++.h>
using namespace std;
// complexity: O(log(max(a,b)))
long long gcd(long long a, long long b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}
struct str
{
    string s;
    string operator*(int n) const
    {
        string tmp = s;
        string ans = "";
        while (n--)
            ans += tmp;
        return ans;
    }
};
void solve()
{
    str a, b;
    cin >> a.s >> b.s;
    int la = a.s.size(), lb = b.s.size();
    if ((a * (lcm(la, lb) / la) == (b * (lcm(la, lb) / lb))))
        cout << (a * (lcm(la, lb) / la)) << "\n";
    else
        cout << "-1\n";
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