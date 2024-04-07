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
    vector<pair<int, int>> str, ans;
    for (int i = 0; i < n; i++)
        str.push_back({a[i], b[i]});
    sort(str.begin(), str.end());
    vector<int> c = a, d = b;
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    for (int i = 0; i < n; i++)
        ans.push_back({c[i], d[i]});
    // bool ok = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     pair<int, int> p = {c[i], d[i]};
    //     auto it = find(str.begin(), str.end(), p);
    //     if (it == str.end())
    //     {
    //         ok = !ok;
    //         break;
    //     }
    //     str.erase(it);
    // }
    if (str != ans)
    {
        cout << "-1\n";
        return;
    }
    str.clear();
    ans.clear();
    for (int i = 0; i < n; i++)
        str.push_back({a[i], b[i]});
    for (int i = 0; i < n; i++)
    {
        int ind = -1;
        pair<int, int> mx = {-1, -1};
        for (int j = 0; j < n - i; j++)
        {
            if (str[j] >= mx)
            {
                mx = str[j];
                ind = j;
            }
        }
        // cout << i << " " << mx.first << "," << mx.second << " " << ind << " " << n - i - 1 << "\n";
        if (ind != n - i - 1)
        {
            // cout << "\n"
            //      << " " << ind << " " << n - i - 1 << "\n";
            ans.push_back({ind, n - i - 1});
            swap(str[ind], str[n - i - 1]);
        }
    }
    cout << ans.size() << "\n";
    for (auto [i, j] : ans)
        cout << i + 1 << " " << j + 1 << "\n";
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