#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
            grid[i][j] += grid[i - 1][j];
        }
    int ans = -1000000000;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            int sum = 0;
            for (int k = 1; k <= n; k++)
            {
                sum += grid[j][k] - grid[i - 1][k];
                ans = max(ans, sum);
                sum = max(sum, 0);
            }
        }
    cout << ans << "\n";
    return 0;
}