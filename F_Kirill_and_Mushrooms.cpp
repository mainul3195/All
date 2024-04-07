#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> v;
struct nd
{
    int val, tot;
    nd()
    {
        val = tot = 0;
    }
    nd(int a, int b)
    {
        val = a;
        tot = b;
    }
    nd operator+(const nd &a) const
    {
        nd tmp = {0, tot + a.tot};
        return tmp;
    }
};
vector<nd> seg_tree;
void build(int node = 1, int start = 1, int end = n)
{
    if (start == end)
    {
        seg_tree[node] = {v[start - 1].first, 1};
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    seg_tree[node] = seg_tree[2 * node] + seg_tree[2 * node + 1];
    return;
}
void erase(int ind, int node = 1, int start = 1, int end = n)
{
    if (start == end)
    {
        seg_tree[node].tot = 0;
        return;
    }
    int mid = (start + end) / 2;
    if (ind <= mid)
        erase(ind, 2 * node, start, mid);
    else
        erase(ind, 2 * node + 1, mid + 1, end);
    seg_tree[node] = seg_tree[2 * node] + seg_tree[2 * node + 1];
    return;
}
int find(int ind, int node = 1, int start = 1, int end = n)
{
    if (start == end)
        return seg_tree[node].val;
    int mid = (start + end) / 2;
    if (ind <= seg_tree[2 * node].tot)
        return find(ind, 2 * node, start, mid);
    return find(ind - seg_tree[2 * node].tot, 2 * node + 1, mid + 1, end);
}
void solve()
{
    cin >> n;
    v = vector<pair<int, int>>(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first, v[i].second = i + 1;
    vector<int> per(n);
    for (auto &i : per)
        cin >> i;
    seg_tree = vector<nd>(4 * n);
    sort(v.rbegin(), v.rend());
    build();
    vector<int> dir(n + 1);
    for (int i = 0; i < n; i++)
        dir[v[i].second] = i + 1;
    int to_take = 1, i = 0;
    long long ans = -1, mn = -1;
    while (to_take <= seg_tree[1].tot)
    {
        // cout << seg_tree[1].tot << " -> ";
        // for (int j = 1; j <= seg_tree[1].tot; j++)
        //     cout << find(j) << " ";
        // cout << "\n";

        int val = find(to_take);
        // cout << to_take << " -> " << val << "\n";
        long long tmp = (long long)to_take * val;
        if (tmp > ans)
        {
            ans = tmp;
            mn = to_take;
        }
        to_take++;
        // cout << "erase: " << dir[per[i]] << "\n";
        erase(dir[per[i++]]);
    }
    cout << ans << " " << mn << "\n";
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
        // cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}