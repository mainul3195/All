#include <bits/stdc++.h>
using namespace std;
struct nd
{
    int x, y, b;
    bool operator<(const nd &a) const
    {
        return x < a.x || (x == a.x && y < a.y);
    }
};
void solve()
{
    int n;
    string grid[2];
    cin >> n;
    cin >> grid[0] >> grid[1];
    set<nd> st;
    st.insert({0, 0, grid[0][0] - '0'});
    long long ans[2][n];
    memset(ans, 0, sizeof(ans));
    ans[0][0] = 1;
    while (st.size())
    {
        set<nd> v;
        for (auto [x, y, _] : st)
        {
            if (x == 1)
            {
                if (y < n - 1)
                    v.insert({x, y + 1, grid[x][y + 1] - '0'});
            }
            else
            {
                if (y < n - 1)
                    v.insert({x, y + 1, grid[x][y + 1] - '0'});
                v.insert({x + 1, y, grid[x + 1][y] - '0'});
            }
        }
        set<nd> tmp;
        for (auto [x, y, b] : v)
            if (b == 0)
                tmp.insert({x, y, b});
        if (tmp.empty())
            tmp = v;
        for (auto [x, y, _] : tmp)
        {
            if (y)
                ans[x][y] += ans[x][y - 1];
            if (x)
                ans[x][y] += ans[x - 1][y];
        }
        st = tmp;
    }
    int i = 0, j = 0;
    while (1)
    {
        cout << grid[i][j];
        if (i == 1 && j == n - 1)
            break;
        if (j < n - 1 && ans[i][j + 1])
            j++;
        else
            i++;
    }
    cout << "\n";
    cout << ans[1][n - 1] << "\n";
    // for (i = 0; i < 2; i++)
    // {
    //     for (j = 0; j < n; j++)
    //         cout << ans[i][j] << " ";
    //     cout << "\n";
    // }
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