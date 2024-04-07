#include <bits/stdc++.h>
using namespace std;
#define inf 1000000
vector<string> mp;
vector<vector<int>> fire_time;
int n, m, x[] = {1, 0, -1, 0}, y[] = {0, -1, 0, 1};
bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}
void solve()
{
    cin >> n >> m;
    mp = vector<string>(n);
    fire_time = vector<vector<int>>(n, vector<int>(m, inf));
    for (auto &s : mp)
        cin >> s;
    bool done = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mp[i][j] == 'F')
            {
                fire_time[i][j] = 0;

                queue<pair<int, int>> q;
                q.push({i, j});
                while (q.size())
                {
                    auto [u, v] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nu = u + x[k];
                        int nv = v + y[k];
                        if (valid(nu, nv) && mp[nu][nv] != '#' && fire_time[nu][nv] > fire_time[u][v] + 1)
                        {
                            fire_time[nu][nv] = fire_time[u][v] + 1;
                            q.push({nu, nv});
                        }
                    }
                }
            }

    done = 0;
    for (int i = 0; !done && i < n; i++)
        for (int j = 0; j < m; j++)
            if (mp[i][j] == 'J')
            {
                fire_time[i][j] = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (q.size())
                {
                    auto [u, v] = q.front();
                    if (u == 0 || v == 0 || u == n - 1 || v == m - 1)
                    {
                        cout << fire_time[u][v] + 1 << "\n";
                        return;
                    }
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nu = u + x[k];
                        int nv = v + y[k];
                        if (valid(nu, nv) && mp[nu][nv] != '#' && fire_time[nu][nv] > fire_time[u][v] + 1)
                        {
                            fire_time[nu][nv] = fire_time[u][v] + 1;
                            q.push({nu, nv});
                        }
                    }
                }
                done = !done;
            }

    cout << "IMPOSSIBLE\n";
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