#include <bits/stdc++.h>
using namespace std;
int h, w;
vector<string> grid;
vector<vector<int>> vis;
#define Mod 998244353
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return (b * bigMod(b, p - 1)) % Mod;
    long long T = bigMod(b, p / 2);
    return (T * T) % Mod;
}
long long modInverse(long long n)
{
    return bigMod(n, Mod - 2);
}
int X[] = {1, 0, -1, 0}, Y[] = {0, -1, 0, 1};
void dfs(int x, int y, int val)
{
    vis[x][y] = val;
    grid[x][y] = '*';
    for (int i = 0; i < 4; i++)
    {
        int nx = x + X[i];
        int ny = y + Y[i];
        if (nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] == '#')
            dfs(nx, ny, val);
    }
    return;
}
void solve()
{
    cin >> h >> w;
    grid = vector<string>(h);
    for (auto &s : grid)
        cin >> s;
    vis = vector<vector<int>>(h, vector<int>(w, 0));
    long long tot_dot_count = 0, val = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (grid[i][j] == '#')
                dfs(i, j, ++val);
    long long up = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (grid[i][j] == '.')
            {
                tot_dot_count++;
                set<int> st;
                for (int k = 0; k < 4; k++)
                {
                    int x = i + X[k];
                    int y = j + Y[k];
                    if (x >= 0 && y >= 0 && x < h && y < w)
                        st.insert(vis[x][y]);
                }
                if (*(st.begin()) == 0)
                    st.erase(st.begin());
                if (st.size())
                    up += val - (st.size() - 1);
                else
                    up += val + 1;
            }
    // cout << up << " " << tot_dot_count << "\n";
    cout << up % Mod * modInverse(tot_dot_count) % Mod << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}