#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int on, toggle;
    nd()
    {
        on = toggle = 0;
    }
};
int n, m;
vector<nd> sg_tree;
long long update(int l, int r, int nd = 1, int start = 1, int end = n, int tg = 0)
{
    if (start > r || end < l)
        return 0;
    if (start >= l && end <= r)
    {
        sg_tree[nd].toggle = !sg_tree[nd].toggle;
        int prev = sg_tree[nd].on;
        sg_tree[nd].on = end-start+1-2*sg_tree[nd].on;
        return sg_tree[nd].on - prev;
    }
    tg = (tg + sg_tree[nd].toggle) % 2;
    int mid = (start + end) / 2;
    int extra = update(l, r, 2 * nd, start, mid, tg) + update(l, r, 2 * nd + 1, mid + 1, end, tg);
    sg_tree[nd].on += extra;
    return extra;
}
long long query(int l, int r, int nd = 1, int start = 1, int end = n, int tg = 0)
{
    if (start > r || end < l)
        return 0;
    if (start >= l && end <= r)
    {
        if (tg)
            return end - start + 1 - 2*sg_tree[nd].on;
        return sg_tree[nd].on;
    }
    (tg += sg_tree[nd].toggle) % 2;
    int mid = (start + end) / 2;
    return query(l, r, 2 * nd, start, mid, tg) + query(l, r, 2 * nd + 1, mid + 1, end, tg);
}
void solve()
{
    cin >> n >> m;
    sg_tree = vector<nd>(4 * n);
    for (int i = 0; i < m; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t)
        {
            if (l == 2 && r == 3)
                cout << query(2, 2) << " " << query(3, 3) << "\n";
            cout << query(l, r) << "\n";
        }
        else
        {
            update(l, r);
            cout << l << " " << r << "\n";
            for (int i = 1; i <= 8; i++)
                cout << i << " -> " << sg_tree[i].toggle << " " << sg_tree[i].on << "\n";
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}