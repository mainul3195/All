#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (auto &i : grid)
        cin >> i;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == 'R')
            {
                bool found = 0;
                for (int k = i + 1; !found && k < h; k++)
                {
                    for (int l = 0; l < j; l++)
                        if (grid[k][l] == 'R')
                        {
                            found = 1;
                            break;
                        }
                }
                if (found)
                    cout << "NO\n";
                else
                    cout << "YES\n";
                return;
            }
        }
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