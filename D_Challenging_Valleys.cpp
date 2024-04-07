#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<int> min_right(n, 2000000000), min_left(n, 2000000000);
    for (int i = 0; i < n; i++)
    {
        if (!i)
            min_left[i] = v[i];
        else
            min_left[i] = min(min_left[i - 1], v[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
            min_right[i] = v[i];
        else
            min_right[i] = min(min_right[i + 1], v[i]);
    }
    for (int i = 0; i < n; i++)
        if (min_left[i] < v[i] && v[i] > min_right[i])
        {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
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