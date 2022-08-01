
#include <bits/stdc++.h>
using namespace std;

struct nd
{
    int l, r, y;
    bool operator<(const nd &a) const
    {
        return y < a.y || (y == a.y && l < a.l) || (y == a.y && l == a.l && r < a.r);
    }
};
#define MAX 1000000

int tree[MAX] = {0}; // To store segment tree
int lazy[MAX] = {0}; // To store pending updates
void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, int diff)
{
    if (lazy[si] != tree[si])
    {
        tree[si] = lazy[si];
        if (ss != se)
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
    }
    if (ss > se || ss > ue || se < us)
        return;

    if (ss >= us && se <= ue)
    {
        tree[si] = lazy[si] = diff;

        if (ss != se)
        {
            lazy[si * 2 + 1] = diff;
            lazy[si * 2 + 2] = diff;
        }
        return;
    }
    int mid = (ss + se) / 2;
    updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
    updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);
    tree[si] = tree[si * 2 + 1] | tree[si * 2 + 2];
}

void updateRange(int n, int us, int ue, int diff)
{
    updateRangeUtil(0, 0, n - 1, us, ue, diff);
}

int getSumUtil(int ss, int se, int qs, int qe, int si)
{
    if (lazy[si] != tree[si])
    {
        tree[si] = lazy[si];
        if (ss != se)
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
    }

    // Out of range
    if (ss > se || ss > qe || se < qs)
        return 0;

    if (ss >= qs && se <= qe)
        return tree[si];
    int mid = (ss + se) / 2;
    return getSumUtil(ss, mid, qs, qe, 2 * si + 1) |
           getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
}

int getSum(int n, int qs, int qe)
{
    return getSumUtil(0, n - 1, qs, qe, 0);
}
void constructSTUtil(int arr[], int ss, int se, int si)
{
    if (ss > se)
        return;
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }
    int mid = (ss + se) / 2;
    constructSTUtil(arr, ss, mid, si * 2 + 1);
    constructSTUtil(arr, mid + 1, se, si * 2 + 2);

    tree[si] = tree[si * 2 + 1] | tree[si * 2 + 2];
}
void constructST(int arr[], int n)
{
    constructSTUtil(arr, 0, n - 1, 0);
}

void solve()
{

    int n, q;
    cin >> n >> q;
    int arr[n + 1];
    for (int i = 0; i <= n; i++)
        arr[i] = 1;

    memset(tree, 0, 4 * n);
    for (int i = 0; i <= 4 * n; i++)
        lazy[i] = 1;

    constructST(arr, n + 1);

    for (int i = 0; i <= 20; i++)
        cout << tree[i] << " ";
    vector<nd> wall(q);
    for (auto &[l, r, y] : wall)
        cin >> l >> r >> y;
    sort(wall.begin(), wall.end());

    for (auto [l, r, y] : wall)
    {
        updateRange(n + 1, l, r, 0);
        updateRange(n + 1, l, l, 1);
        updateRange(n + 1, r, r, 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (getSum(n + 1, i, i))
            ans++;
    cout << ans << "\n";

    int i = 0;
    for (int j = 0; i < 20; j++)
    {
        for (int k = 0; k < (1 << j); k++)
            cout << tree[i++] << " ";
        cout << "\n";
    }
    // cout << "\n";
    // // Print sum of values in array from index 1 to 3
    // printf("Sum of values in given range = %d\n",
    //        getSum(n, 1, 3));

    // // Add 10 to all nodes at indexes from 1 to 5.
    // updateRange(n, 2, 5, 0);

    // // Find sum after the value is updated
    // printf("Updated sum of values in given range = %d\n",
    //        getSum(n, 1, 3));
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}