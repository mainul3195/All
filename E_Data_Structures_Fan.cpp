#include <bits/stdc++.h>
using namespace std;
int n;
struct nd
{
    long long Xr[2], lazy;
    nd()
    {
        Xr[0] = Xr[1] = lazy = 0;
    }
};
vector<nd> seg_tree;
vector<int> v;
string s;
void build(int node = 1, int start = 1, int end = n)
{
    if (start == end)
    {
        int ind = start - 1;
        if (s[ind] == '0')
            seg_tree[node].Xr[0] = v[ind];
        else
            seg_tree[node].Xr[1] = v[ind];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    for (int i = 0; i < 2; i++)
        seg_tree[node].Xr[i] = seg_tree[2 * node].Xr[i] ^ seg_tree[2 * node + 1].Xr[i];
    return;
}
void push_down(int nd, int s, int e)
{
    int lz = seg_tree[nd].lazy % 2;
    seg_tree[nd].lazy = 0;
    if (!lz)
        return;
    swap(seg_tree[nd].Xr[0], seg_tree[nd].Xr[1]);
    if (s != e)
    {
        seg_tree[2 * nd].lazy++;
        seg_tree[2 * nd + 1].lazy++;
    }
    return;
}
void upd(int l, int r, int node = 1, int start = 1, int end = n)
{
    if (seg_tree[node].lazy)
        push_down(node, start, end);
    if (start > r || end < l)
        return;
    if (start >= l && end <= r)
    {
        seg_tree[node].lazy++;
        push_down(node, start, end);
        return;
    }
    int mid = (start + end) / 2;
    upd(l, r, 2 * node, start, mid);
    upd(l, r, 2 * node + 1, mid + 1, end);
    for (int i = 0; i < 2; i++)
        seg_tree[node].Xr[i] = seg_tree[2 * node].Xr[i] ^ seg_tree[2 * node + 1].Xr[i];
    return;
}
void solve()
{
    cin >> n;
    v = vector<int>(n);
    for (auto &i : v)
        cin >> i;
    cin >> s;
    seg_tree = vector<nd>(4 * n);
    build();
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 2)
        {
            int g;
            cin >> g;
            cout << seg_tree[1].Xr[g] << " ";
        }
        else
        {
            int l, r;
            cin >> l >> r;
            upd(l, r);
        }
    }
    cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}