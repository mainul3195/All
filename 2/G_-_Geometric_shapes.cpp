#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> visited;
int n, m, r, c, cnt;
int x[] = {0, 1, 0, -1}, y[] = {1, 0, -1, 0};
bool valid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < n && j < m && visited[i][j] == -1);
}
bool done;
void circ(int i, int j, int nm)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    while (q.size() && cnt != 4)
    {
        auto [u, v] = q.front();
        q.pop();
        visited[u][v] = nm;
        cnt++;
        if (cnt == 4)
            break;
        for (int k = 0; k < 4; k++)
        {
            int tu = u + x[k];
            int ty = v + y[k];
            if (valid(tu, ty))
                q.push({tu, ty});
        }
    }
}
void solve()
{
    cin >> n >> m >> r >> c;
    if ((n * m - 1) % 4)
    {
        cout << "NO\n";
        return;
    }
    visited = vector<vector<int>>(n, vector<int>(m, -1));
    visited[r - 1][c - 1] = 0;
    int itm = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == -1)
            {
                cnt = 0;
                circ(i, j, itm++);
                if (cnt != 4)
                {
                    for (auto v : visited)
                    {
                        for (auto i : v)
                            cout << i << " ";
                        cout << "\n";
                    }
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
    for (auto v : visited)
    {
        for (auto i : v)
            cout << i << " ";
        cout << "\n";
    }
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