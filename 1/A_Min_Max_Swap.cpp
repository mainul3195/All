#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    for (int i = 0; i < n; i++)
        if (a[i] < b[i])
            swap(a[i], b[i]);
    int mn1 = 0, mn2 = 0;
    for (auto i : a)
        mn1 = max(mn1, i);
    for (auto i : b)
        mn2 = max(mn2, i);
    cout << mn1 * mn2 << "\n";
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