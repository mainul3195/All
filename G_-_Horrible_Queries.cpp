#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, c;
struct node
{
    long long sum, lazy;
    node()
    {
        sum = 0;
        lazy = 0;
    }
};
vector<node> segment_tree;
long long get_sum(int nd, int start, int end, int left, int right, long long lz = 0)
{
    if (start > end || start > right || end < left)
    {
        return 0;
    }
    lz += segment_tree[nd].lazy;
    if (start >= left && end <= right)
    {
        return segment_tree[nd].sum + lz * (end - start + 1);
    }
    int mid = (start + end) / 2;
    return get_sum(nd * 2, start, mid, left, right, lz) + get_sum(nd * 2 + 1, mid + 1, end, left, right, lz);
}
long long update(int nd, int start, int end, int left, int right, int val)
{
    if (start > end || start > right || end < left)
    {
        return 0;
    }
    if (start >= left && end <= right)
    {
        segment_tree[nd].lazy += val;
        return val * (end - start + 1);
    }
    int mid = (start + end) / 2;
    long long extra = update(2 * nd, start, mid, left, right, val) + update(2 * nd + 1, mid + 1, end, left, right, val);
    segment_tree[nd].sum += extra;
    return extra;
}
void print_tree()
{
    for (int i = 1; i <= 15; i++)
    {
        cout << i << "-> \n";
        cout << segment_tree[i].lazy << " " << segment_tree[i].sum << "\n";
    }
    cout << "\n\n";
    return;
}
void solve()
{
    // cout << "this\n";
    cin >> n >> c;
    segment_tree = vector<node>(4 * n);
    for (int i = 0; i < c; i++)
    {
        // cout << "here\n";
        int t;
        cin >> t;
        if (t)
        {
            int l, r;
            cin >> l >> r;
            cout << get_sum(1, 1, n, l, r) << "\n";
        }
        else
        {
            int l, r, v;
            cin >> l >> r >> v;
            // cout << l << " " << r << " " << v << "\n";
            update(1, 1, n, l, r, v);
        }
    }
    // print_tree();
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
