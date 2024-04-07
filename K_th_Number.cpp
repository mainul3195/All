#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int val, i1, i2;
    bool operator<(const nd &a) const
    {
        return val < a.val;
    }
};
struct node
{
    long long sum, l, r;
    node *left, *right;
    node()
    {
        sum = 0;
        left = right = NULL;
    }
    node(int val)
    {
        sum = val;
        left = right = NULL;
    }
    node(node &a, node &b)
    {
        sum = a.sum + b.sum;
        left = &a;
        right = &b;
    }
};
int n, q;
vector<node> roots;
vector<nd> ar, str;
node *build(int start = 0, int end = n - 1)
{
    if (start == end)
    {
        return new node(0);
    }
    int mid = (start + end) / 2;
    return new node(*build(start, mid), *build(mid + 1, end));
}
node *update(node root, int ind, int val, int start = 0, int end = n - 1)
{
    if (start == end)
        return new node(val);
    int mid = (start + end) / 2;
    return ind <= mid ? new node(*update(*root.left, ind, val, start, mid), *root.right) : new node(*root.left, *update(*root.right, ind, val, mid + 1, end));
}
int query(node l, node r, int k, int start = 0, int end = n - 1)
{
    if (start == end)
    {
        return ar[start].val;
    }
    int avail = (*r.left).sum - (*l.left).sum;
    return k <= avail ? query(*l.left, *r.left, k, start, (start + end) / 2) : query(*l.right, *r.right, k - avail, (start + end) / 2 + 1, end);
}
void print_tree(node root)
{
    queue<node> q;
    q.push(root);
    int count = 0;
    while (q.size())
    {
        count++;
        node u = q.front();
        q.pop();
        cout << u.sum << " ";
        if (u.left != NULL)
        {
            q.push(*u.left);
            q.push(*u.right);
        }
    }
    cout << "\n";
    return;
}
void solve()
{
    cin >> n >> q;
    ar = vector<nd>(n);
    roots.push_back(*build());
    int ind = 0;
    for (auto &[a, b, c] : ar)
    {
        cin >> a;
        b = ind++;
    }
    str = ar;
    sort(ar.begin(), ar.end());
    for (int i = 0; i < n; i++)
    {
        ar[i].i2 = i;
        str[ar[i].i1].i2 = i;
    }
    for (auto [a, b, c] : str)
        roots.push_back(*update(roots.back(), c, 1));
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << query(roots[l - 1], roots[r], k) << "\n";
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