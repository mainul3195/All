#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int mx, mxi, mn, mni;
    nd()
    {
        mx = -10000000;
        mxi = 0;
        mn = 1000000000;
        mni = 0;
    }
    nd(int _mx, int _mxi, int _mn, int _mni)
    {
        mx = _mx;
        mxi = _mxi;
        mn = _mn;
        mni = _mni;
    }
    nd operator+(const nd &a) const
    {
        nd tmp;
        tmp.mx = max(mx, a.mx);
        if (mx > a.mx)
            tmp.mxi = mxi;
        else
            tmp.mxi = a.mxi;
        tmp.mn = min(mn, a.mn);
        if (mn < a.mn)
            tmp.mni = mni;
        else
            tmp.mni = a.mni;
        return tmp;
    }
    void prnt()
    {
        cout << "(" << mx << ", " << mxi << ", " << mn << ", " << mni << ")\n";
        return;
    }
};
vector<nd> sg_tree;
vector<int> v;
int n;
void build(int start = 0, int end = n - 1, int node = 1)
{
    if (start > end)
        return;
    if (start == end)
    {
        sg_tree[node] = {v[start], start, v[start], start};
        return;
    }
    int mid = (start + end) / 2;
    int left = 2 * node;
    int right = left + 1;
    build(start, mid, left);
    build(mid + 1, end, right);
    sg_tree[node] = sg_tree[left] + sg_tree[right];
    return;
}
nd query(int l, int r, int node = 1, int start = 0, int end = n - 1)
{
    if (start > r || end < l || l > r)
    {
        nd _nd;
        return _nd;
    }
    if (start >= l && end <= r)
        return sg_tree[node];
    int mid = (start + end) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    return query(l, r, left, start, mid) + query(l, r, right, mid + 1, end);
}
void print_tree()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << i << " ->";
        sg_tree[i].prnt();
    }
}
void solve()
{
    cin >> n;
    v = vector<int>(n);
    for (auto &i : v)
        cin >> i;
    sg_tree = vector<nd>(4 * n);
    build();
    // print_tree();
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        nd nam_khuija_painai = query(l, r);
        nd in1 = nam_khuija_painai.mni > l ? query(l, nam_khuija_painai.mni - 1) : (nd){0, 0, 0, 0};
        nd in2 = nam_khuija_painai.mni < r ? query(nam_khuija_painai.mni + 1, r) : (nd){0, 0, 0, 0};
        nd out1 = l > 0 ? query(0, l - 1) : (nd){0, 0, 0, 0};
        nd out2 = r < n - 1 ? query(r + 1, n - 1) : (nd){0, 0, 0, 0};
        int tmp = (2 * nam_khuija_painai.mn + max({2 * out1.mx, 2 * out2.mx, max(0, in1.mx - nam_khuija_painai.mn), max(0, in2.mx - nam_khuija_painai.mn)}));
        cout <<  tmp/2 << (tmp&1? ".5": ".0") << "\n";
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