#include <bits/stdc++.h>
using namespace std;
#define int long long
long long value(vector<int> &pos, vector<vector<long long>> &a)
{
    long long tot = 0;
    for (int i = 0; i < a.size(); i++)
        tot += a[i][pos[i] - 1];
    return tot;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<long long>> a(n);
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
    vector<vector<int>> v_ban;
    for (int i = 0; i < m; i++)
    {
        vector<int> vc(n);
        for (auto &j : vc)
            cin >> j;
        v_ban.push_back(vc);
        banned.insert(vc);
    }
    vector<int> ans;
    for (auto i : a)
        ans.push_back(i.size());
    if (banned.find(ans) != banned.end())
    {
        long long mx = 0;
        for (auto v : v_ban)
        {
            vector<int> tmp = v;
            for (int i = 0; i < v.size(); i++)
                if (v[i] > 1)
                {
                    tmp[i] = v[i] - 1;
                    if (banned.find(tmp) != banned.end())
                    {
                        tmp[i] = v[i];
                        continue;
                    }
                    long long vl = value(tmp, a);
                    if (vl > mx)
                    {
                        mx = vl;
                        ans = tmp;
                    }
                    tmp[i] = v[i];
                }
        }
    }

    for (auto i : ans)
        cout << i << " ";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}