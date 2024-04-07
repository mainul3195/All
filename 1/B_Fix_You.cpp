#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (auto &i : grid)
        cin >> i;
    int count = 0;
    for (int i = 0; i < h - 1; i++)
        if (grid[i][w - 1] == 'R')
            count++;
    for (int i = 0; i < w - 1; i++)
        if (grid[h - 1][i] == 'D')
            count++;
    cout << count << "\n";
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