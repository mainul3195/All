#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<int> avail;
    for (int i = 1; i <= n; i++)
        avail.push_back(i);
    vector<int> ans(n, 0);
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
        {
            int dif = v[i - 1] - v[i];
            auto it = lower_bound(avail.begin(), avail.end(), dif);
            ans[*it - 1] = i + 1;
            avail.erase(it);
        }
    }
    for (auto &i : ans)
        if (!i)
            i = 1;
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}