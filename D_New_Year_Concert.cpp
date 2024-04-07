#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> v, sg_tree;
void build(int node = 1, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        sg_tree[node] = v[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    sg_tree[node] = __gcd(sg_tree[2 * node], sg_tree[2 * node + 1]);
    return;
}
long long query(int l, int r, int node = 1, int start = 0, int end = n - 1)
{
    if (end < l || start > r)
        return 0;
    if (start >= l && end <= r)
        return sg_tree[node];
    int mid = (start + end) / 2;
    return __gcd(query(l, r, 2 * node, start, mid), query(l, r, 2 * node + 1, mid + 1, end));
}
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
void solve()
{
    cin >> n;
    sg_tree = vector<long long>(4 * n);
    v = vector<long long>(n);
    for (auto &i : v)
        cin >> i;
    build();
    vector<pair<int, int>> segs;
    for (int i = 0; i < n; i++)
    {
        int l = i, r = n - 1, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            int g = query(i, mid);
            if (g == mid - i + 1)
            {
                segs.push_back({i, mid});
                break;
            }
            if (g < mid - i + 1)
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
    sort(segs.begin(), segs.end(), cmp);
    vector<int> ans(n, 0);
    int last = -1;
    for (auto [a, b] : segs)
        if (a > last)
        {
            ans[b]++;
            last = b;
        }
    int tot = 0;
    for (auto i : ans)
    {
        tot += i;
        cout << tot << " ";
    }
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}