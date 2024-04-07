#include <bits/stdc++.h>
using namespace std;
vector<int> sg_tree, nm, ans;
int n;
void make(int node = 1, int s = 1, int e = n)
{
    if (s == e)
    {
        sg_tree[node] = nm[s - 1];
        return;
    }
    int left = node << 1;
    int right = left + 1;
    int mid = (s + e) >> 1;
    make(left, s, mid);
    make(right, mid + 1, e);
    sg_tree[node] = min(sg_tree[left], sg_tree[right]);
    return;
}
int query(int l, int r, int node = 1, int s = 1, int e = n)
{
    if (e < l || r < s)
        return 2147483647;
    if (s >= l && e <= r)
        return sg_tree[node];
    int left = node << 1;
    int right = left + 1;
    int mid = (s + e) >> 1;
    return min(query(l, r, left, s, mid), query(l, r, right, mid + 1, e));
}
void solve()
{
    cin >> n;
    nm = vector<int>(n);
    ans = vector<int>(n + 1, 0);
    for (auto &i : nm)
        cin >> i;
    sg_tree = vector<int>(4 * n);
    make();
    ans[n] = query(1, n) == 1;
    vector<int> v = nm;
    sort(v.begin(), v.end());
    bool ok = 1;
    for (int i = 0; i < n; i++)
        if (v[i] != i + 1)
        {
            ok = 0;
            break;
        }
    ans[1] = ok;
    int l = 1, r = n;
    if (ans[n])
        for (int i = n - 1; i > 0; i--)
        {
            int val = n - i;
            if (nm[l - 1] == val && query(l + 1, r) == val + 1)
            {
                l++;
                ans[i] = 1;
            }
            else if (nm[r - 1] == val && query(l, r - 1) == val + 1)
            {
                r--;
                ans[i] = 1;
            }
            else
                break;
        }
    for (int i = 1; i <= n; i++)
        cout << ans[i];
    cout << "\n";
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