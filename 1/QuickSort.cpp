#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int l, int r)
{
    int i = l - 1, pivot = v[r];
    for (int j = l; j < r; j++)
        if (v[j] <= pivot)
            swap(v[++i], v[j]);
    swap(v[++i], v[r]);
    return i;
}
void quicksort(vector<int> &v, int l, int r)
{
    if (l < r)
    {
        int pos = partition(v, l, r);
        quicksort(v, l, pos - 1);
        quicksort(v, pos + 1, r);
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
    quicksort(v, 0, n - 1);
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