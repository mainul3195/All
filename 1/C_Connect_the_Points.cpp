#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<pair<int, int>> pt(3);
    for (auto &[x, y] : pt)
        cin >> x >> y;
    sort(pt.begin(), pt.end());
    vector<vector<pair<int, int>>> ans;
    pair<int, int> low, high;
    if (pt[0].first == pt[1].first)
    {
        ans.push_back({pt[0], pt[1]});
        if (pt[0].second < pt[1].second)
            low = pt[0], high = pt[1];
        else
            low = pt[1], high = pt[0];
    }
    else if (pt[0].second == pt[1].second)
        ans.push_back({pt[0], pt[1]}), low = high = pt[1];
    else
    {
        ans.push_back({pt[0], {pt[1].first, pt[0].second}});
        ans.push_back({{pt[1].first, pt[0].second}, pt[1]});
        if (pt[0].second < pt[1].second)
            low = {pt[1].first, pt[0].second}, high = pt[1];
        else
            low = pt[1], high = {pt[1].first, pt[0].second};
    }
    pair<int, int> from;

    int y1 = pt[0].second, y2 = pt[1].second;
    if (y1 > y2)
        swap(y1, y2);
    if(pt[2].second>y2)
        from = high;
    else if(pt[2].second<y1)
        from = low;
    else
        from = {low.first, pt[2].second};

    if (from.first == pt[2].first || from.second == pt[2].second)
        ans.push_back({from, pt[2]});
    else
    {
        ans.push_back({from, {pt[2].first, from.second}});
        ans.push_back({{pt[2].first, from.second}, pt[2]});
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
    {
        for (auto [x, y] : i)
            cout << x << " " << y << " ";
        cout << "\n";
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}