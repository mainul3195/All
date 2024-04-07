#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> segs(n);
    int mx = -1;
    for (auto &[l, r] : segs)
    {
        cin >> l >> r;
        mx = max({mx, l, r});
    }
    vector<vector<int>> strt(mx + 1), khattam(mx + 1);
    for (int i = 0; i < n; i++)
    {
        strt[segs[i].first].push_back(i);
        khattam[segs[i].second].push_back(i);
    }
    set<pair<int, int>> q;
    vector<int> ans;
    for (int i = 0; i <= mx; i++)
    {
        while (q.size() && (*q.begin()).first < i)
            q.erase(q.begin());
        for (auto ind : strt[i])
            q.insert({segs[ind].second, ind});
        while (q.size() > k)
        {
            ans.push_back((*(q.rbegin())).second);
            auto it = q.end();
            it--;
            q.erase(it);
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i + 1 << " ";
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