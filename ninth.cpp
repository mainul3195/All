#include <bits/stdc++.h>
using namespace std;
struct nd
{
    long long sum, mn, mx;
    nd()
    {
        sum = 0;
        mn = 1000000000000000;
        mx = -1000000000000000;
    }
    nd(long long v)
    {
        sum = mn = mx = v;
    }
};
nd combine(nd a, nd b)
{
    nd c;
    c.sum = a.sum + b.sum;
    c.mn = min(a.mn, b.mn);
    c.mx = max(a.mx, b.mx);
    return c;
}
int n;
vector<nd> seg_tree;
void update(int ind, long long val, int node = 1, int start = 1, int end = n)
{
    if (start == end)
    {
        seg_tree[node] = nd(val);
        return;
    }
    int mid = (start + end) / 2;
    ind <= mid ? update(ind, val, 2 * node, start, mid) : update(ind, val, 2 * node + 1, mid + 1, end);
    seg_tree[node] = combine(seg_tree[2 * node], seg_tree[2 * node + 1]);
    return;
}
nd query(int l, int r, int node = 1, int start = 1, int end = n)
{
    if (start > r || end < l)
        return nd();
    if (start >= l && end <= r)
        return seg_tree[node];
    int mid = (start + end) / 2;
    return combine(query(l, r, 2 * node, start, mid), query(l, r, 2 * node + 1, mid + 1, end));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("hel.in", "r", stdin);
    // freopen("hel.out", "w", stdout);
    cin >> n;
    seg_tree = vector<nd>(4 * n);
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        update(i + 1, x);
    }
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "assign")
        {
            int i, v;
            cin >> i >> v;
            update(i, v);
        }
        else
        {
            int l, r;
            long long e;
            cin >> l >> r >> e;
            nd qr = query(l, r);
            long long v;
            if (e <= 0)
                v = qr.mn;
            else
                v = qr.mx;
            cout << qr.sum - v + v * e << "\n";
        }
    }
    return 0;
}