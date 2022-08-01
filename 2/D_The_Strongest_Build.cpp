#include <bits/stdc++.h>
using namespace std;

struct pr
{
    long long val, pos;
    bool operator<(const pr &nw) const
    {
        return val < nw.val || (val == nw.val && pos < nw.pos);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<vector<long long>> a(n);
    set<pr> all;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            int u;
            cin >> u;
            a[i].push_back(u);
        }
    }
    set<vector<int>> banned;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        vector<int> vc(n);
        for (auto &j : vc)
            cin >> j;
        banned.insert(vc);
    }
    vector<int> ans;
    for (auto i : a)
        ans.push_back(i.size());
    while (banned.find(ans) != banned.end())
    {
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