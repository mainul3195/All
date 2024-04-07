#include <bits/stdc++.h>
using namespace std;
int sx, sy, dx, dy, X[] = {1, 1, 1, 0, -1, -1, -1, 0}, Y[] = {1, 0, -1, -1, -1, 0, 1, 1};
map<pair<int, int>, int> mp;
void solve()
{
    cin >> sx >> sy >> dx >> dy;
    int m;
    cin >> m;
    while (m--)
    {
        int r, a, b;
        cin >> r >> a >> b;
        for (int i = a; i <= b; i++)
            mp[{r, i}] = -1;
    }
    queue<pair<int, int>> q;
    q.push({sx, sy});
    mp[{sx, sy}] = 0;
    while (q.size())
    {
        auto [r, c] = q.front();
        q.pop();
        if (r == dx && c == dy)
        {
            cout << mp[{r, c}] << "\n";
            return;
        }
        int dis = mp[{r, c}];
        for (int i = 0; i < 8; i++)
        {
            int u = r + X[i];
            int v = c + Y[i];
            if (mp.find({u, v}) != mp.end() && mp[{u, v}] == -1)
            {
                mp[{u, v}] = dis + 1;
                q.push({u, v});
            }
        }
    }
    cout << "-1\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}