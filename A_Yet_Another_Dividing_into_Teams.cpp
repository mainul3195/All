#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    bool ok = 1;
    for (int i = 1; i < n; i++)
        if (v[i] - v[i - 1] == 1)
        {
            ok = !ok;
            break;
        }
    if (ok)
        cout << "1\n";
    else
        cout << "2\n";
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