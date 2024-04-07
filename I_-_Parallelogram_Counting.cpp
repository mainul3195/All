#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v, mids;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            mids.push_back({v[i].first + v[j].first, v[i].second + v[j].second});

    sort(mids.begin(), mids.end());

    long long ans = 0;
    for (int i = 0; i < mids.size(); i++)
    {
        pair<int, int> p = mids[i];
        long long count = 0;
        while (i < mids.size() && mids[i] == p)
        {
            count++;
            i++;
        }
        i--;
        ans += count * (count - 1) / 2;
    }
    cout << ans << "\n";
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
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}