#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int mxv, mxc, smxv, smxc;
    nd merge(nd a)
    {
        nd tmp;
        vector<pair<int, int>> v;
        v.push_back({mxv, mxc});
        v.push_back({smxv, smxc});
        v.push_back({a.mxv, a.mxc});
        v.push_back({a.smxv, a.smxc});
        sort(v.begin(), v.end());
        tmp.mxv = v.back().first;
        tmp.mxc = 0;
        while (v.size())
        {
            if (v.back().first != tmp.mxv)
                break;
            tmp.mxc += v.back().second;
            v.pop_back();
        }
        if (v.size())
        {
            tmp.smxv = v.back().first;
            tmp.smxc = 0;
            while (v.size())
            {
                if (v.back().first != tmp.smxv)
                    break;
                tmp.smxc += v.back().second;
                v.pop_back();
            }
        }
        else
        {
            tmp.smxv = -1;
            tmp.smxc = 0;
        }
        return tmp;
    }
};
int n, q;
vector<nd> seg_tree;
vector<int> a;
void build(int node = 1, int start = 1, int end = n)
{
    if (start == end)
    {
        seg_tree[node] = {a[start], 1, -1, 0};
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    seg_tree[node] = seg_tree[2 * node].merge(seg_tree[2 * node + 1]);
    return;
}
void update(int ind, int val, int node = 1, int start = 1, int end = n)
{
    if (start == end)
    {
        seg_tree[node] = {val, 1, -1, 0};
        return;
    }
    int mid = (start + end) / 2;
    ind <= mid ? update(2 * node, start, mid) : update(2 * node + 1, mid + 1, end);
    seg_tree[node] = seg_tree[2 * node].merge(seg_tree[2 * node + 1]);
    return;
}
nd query(int l, int r, int node = 1, int start = 1, int end = n)
{
    if (start > r || end < l)
        return {-1, -1, -1, -1};
    if (start >= l && end <= r)
        return seg_tree[node];
    int mid = (start + end) / 2;
    return query(l, r, 2 * node, start, mid).merge(query(l, r, 2 * node + 1, mid + 1, end));
}
void solve()
{
    cin >> n >> q;
    seg_tree = vector<nd>(4 * n);
    a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build();
    while(q--)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if(t==1)
            update(a, b);
        else
            cout << query(a, b).smxc << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}