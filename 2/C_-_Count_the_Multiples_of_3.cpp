#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int div1, div2, div3, lazy;
    nd()
    {
        div1 = div2 = div3 = lazy = 0;
    }
    nd(int _div1, int _div2, int _div3, int _lazy)
    {
        div1 = _div1;
        div2 = _div2;
        div3 = _div3;
        lazy = _lazy;
    }
    nd operator+(const nd &a) const
    {
        return (nd){div1 + a.div1, div2 + a.div2, div3 + a.div3, lazy + a.lazy};
    }
};
int n, q;
vector<nd> sg_tree;
void push_down(int node, int l, int r)
{

    int prev = sg_tree[node].lazy;
    sg_tree[node].lazy %= 3;
    int new1 = sg_tree[node].div1, new2 = sg_tree[node].div2, new3 = sg_tree[node].div3;
    if (sg_tree[node].lazy == 1)
    {
        new1 = sg_tree[node].div3;
        new2 = sg_tree[node].div1;
        new3 = sg_tree[node].div2;
    }
    else if (sg_tree[node].lazy == 2)
    {
        new1 = sg_tree[node].div2;
        new2 = sg_tree[node].div3;
        new3 = sg_tree[node].div1;
    }
    sg_tree[node].div1 = new1;
    sg_tree[node].div2 = new2;
    sg_tree[node].div3 = new3;
    if (l != r)
    {
        sg_tree[2 * node].lazy += prev;
        sg_tree[2 * node + 1].lazy += prev;
    }
    sg_tree[node].lazy = 0;
    return;
}
void update(int l, int r, int node = 1, int start = 0, int end = n - 1)
{
    if (sg_tree[node].lazy)
        push_down(node, start, end);
    if (start > r || end < l)
        return;
    if (start >= l && end <= r)
    {
        sg_tree[node].lazy++;
        push_down(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    update(l, r, node * 2, start, mid);
    update(l, r, node * 2 + 1, mid + 1, end);
    sg_tree[node] = sg_tree[2 * node] + sg_tree[2 * node + 1];
    return;
}
int query(int l, int r, int node = 1, int start = 0, int end = n - 1)
{
    if (sg_tree[node].lazy)
        push_down(node, start, end);
    if (start > r || end < l)
        return 0;
    if (start >= l && end <= r)
        return sg_tree[node].div3;
    int mid = (start + end) / 2;
    return query(l, r, 2 * node, start, mid) + query(l, r, 2 * node + 1, mid + 1, end);
    return 0;
}
void build(int node = 1, int start = 0, int end = n - 1)
{
    sg_tree[node].div3 = end - start + 1;
    if (start == end)
        return;
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
}
void print_tree()
{
    for (int i = 1; i < 30; i++)
    {
        cout << i << " -> ";
        cout << "(l, 1, 2, 3) -> (" << sg_tree[i].lazy << " " << sg_tree[i].div1 << " " << sg_tree[i].div2 << " " << sg_tree[i].div3 << ")\n";
    }
    return;
}
void solve()
{
    cin >> n >> q;
    sg_tree = vector<nd>(4 * n);
    build();
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        // cout << t << l << r << endl;
        if (t)
            cout << query(l, r) << "\n";
        else
            update(l, r);
        // print_tree();
        // cout << "\n";
    }
    return;
}
int32_t main()
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