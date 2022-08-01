#include <bits/stdc++.h>
using namespace std;

void merging(vector<int> &a, int l, int mid, int r)
{
    vector<int> c;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j])
            c.push_back(a[i++]);
        else
            c.push_back(a[j++]);
    }
    while (i <= mid)
        c.push_back(a[i++]);
    while (j <= r)
        c.push_back(a[j++]);
    int ind = l;
    for (auto i : c)
        a[ind++] = i;
    return;
}
void mergesort(vector<int> &v, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergesort(v, l, mid);
        mergesort(v, mid + 1, r);
        merging(v, l, mid, r);
    }
    return;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    mergesort(v, 0, n - 1);
    for (auto i : v)
        cout << i << " ";
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