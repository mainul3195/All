#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<vector<int>> price;
vector<int> cash;
vector<int> items;
void solve()
{
    cin >> n >> m;
    items = vector<int>(m);
    price = vector<vector<int>>(n);
    cash = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int item;
            cin >> item;
            price[i].push_back(item);
        }
        cin >> cash[i];
    }
    for (auto &i : items)
        cin >> i;
    long long tot = 0;
    for (int i = 0; i < n; i++)
    {
        int mx = 10000;
        for (auto ind : price[i])
            mx = min(mx, items[ind - 1]);
        tot += mx * cash[i];
    }
    cout << tot << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}