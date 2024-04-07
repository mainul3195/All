// using segment tree

#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> sg_tree;
void build(int ind, int val, int nd = 1, int start = 1, int end = n)
{
    if (ind < start || ind > end)
        return;
    sg_tree[nd] = min(sg_tree[nd], val);
    if (start == end)
        return;
    int mid = (start + end) / 2;
    ind <= mid ? build(ind, val, nd * 2, start, mid) : build(ind, val, nd * 2 + 1, mid + 1, end);
}
int query(int l, int r, int nd = 1, int start = 1, int end = n)
{
    // cout << l << " " << r << " " << nd << " " << start << " " << end << "\n";
    if (start > r || end < l)
        return 10000000;
    if (start >= l && end <= r)
        return sg_tree[nd];
    int mid = (start + end) / 2;
    return min(query(l, r, 2 * nd, start, mid), query(l, r, 2 * nd + 1, mid + 1, end));
}
void solve()
{
    cin >> n >> q;
    sg_tree = vector<int>(4 * n, 10000000);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        build(i, x);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        // cout << l << " " << r << "\n";
        cout << query(l, r) << "\n";
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ":\n";
        solve();
    }
    return 0;
}