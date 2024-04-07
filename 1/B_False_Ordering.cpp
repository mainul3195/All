#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> nod(1001);
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second || (a.second == b.second && a.first > b.first);
}
void solve()
{
    int n;
    cin >> n;
    cout << nod[n].first << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i <= 1000; i++)
        nod[i] = {i, 0};
    for (int i = 1; i <= 1000; i++)
        for (int j = i; j <= 1000; j += i)
            nod[j].second++;
    sort(nod.begin(), nod.end(), cmp);
    int t = 1, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
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