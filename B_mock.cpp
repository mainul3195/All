#include <bits/stdc++.h>
using namespace std;
long long ar[100000000];
vector<vector<char>> grid;
void make(int i, int j, int n)
{
    if (n == 1)
    {
        grid[i][j] = grid[i][j - 1] = '_';
        grid[i][j - 2] = '|';
        grid[i][j - 3] = '-';
        grid[i][j - 4] = '-';
        grid[i][j - 5] = 'o';
        grid[i + 1][j - 2] = '|';
        grid[i + 1][j - 3] = '-';
        grid[i + 1][j - 4] = '-';
        grid[i + 1][j - 5] = 'o';
        return;
    }
    grid[i][j] = grid[i][j - 1] = '_';
    int lim = 1 << (n - 2);
    for (int k = i, l = i + 1, cnt = 0; cnt < lim; k--, cnt++, l++)
        grid[k][j - 2] = grid[l][j - 2] = '|';
    make(i - lim, j - 3, n - 1);
    make(i + lim, j - 3, n - 1);
    return;
}
void solve()
{
    int n;
    cin >> n;
    int row = (1 << n);
    int col = (n + 1) * 3;
    grid = vector<vector<char>>(row, vector<char>(col, '.'));
    make((row - 1) / 2, col - 1, n);
    for (int i = 0; i < row; i++)
        for (int j = col - 1; j >= 0; j--)
        {
            if (grid[i][j] == '.')
                grid[i][j] = ',';
            else
                break;
        }

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         // if (grid[i][j] == '.')
    //         //     grid[i][j] = ' ';
    //         // else if (grid[i][j] == ',')
    //         //     break;
    //         cout << grid[i][j];
    //     }
    //     cout << "\n";
    // }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == '.')
                grid[i][j] = ' ';
            else if (grid[i][j] == ',')
                break;
            cout << grid[i][j];
        }
        cout << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i <= 100000003; i++)
        ar[i] = i;
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ":\n";
        solve();
    }
    return 0;
}
