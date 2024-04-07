#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    cin >> m;
    vector<int> b(m);
    for (auto &i : b)
        cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int am = upper_bound(a.begin(), a.end(), a[n - 1]) - lower_bound(a.begin(), a.end(), a[n - 1]);
    int bm = upper_bound(b.begin(), b.end(), b[m - 1]) - lower_bound(b.begin(), b.end(), b[m - 1]);

    if (a[n - 1] >= b[m - 1])
        cout << "Alice\n";
    else
        cout << "Bob\n";

    if (b[m - 1] >= a[n - 1])
        cout << "Bob\n";
    else
        cout << "Alice\n";
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