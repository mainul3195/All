#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>>
        dr,
        mn(n, vector<int>(n)),
        p2(n + 1, vector<int>(n + 1, 0)),
        p5(n + 1, vector<int>(n + 1, 0)),
        dp2(n + 1, vector<int>(n + 1, 0)),
        dp5(n + 1, vector<int>(n + 1, 0)),
        dir2(n + 1, vector<int>(n + 1, 0)),
        dir5(n + 1, vector<int>(n + 1, 0));
    bool found = 0;
    pair<int, int> ind;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mn[i][j];
            if (mn[i][j] == 0)
            {
                found = 1;
                ind = {i, j};
                mn[i][j] = 10;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int c1 = 0, c2 = 0;
            int nm = mn[i][j];
            while (nm % 2 == 0)
            {
                c1++;
                nm >>= 1;
            }
            while (nm % 5 == 0)
            {
                c2++;
                nm /= 5;
            }
            p2[i + 1][j + 1] = c1;
            p5[i + 1][j + 1] = c2;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int up = dp2[i - 1][j] + p2[i][j];
            int left = dp2[i][j - 1] + p2[i][j];
            if ((up < left || j == 1) && i != 1)
            {
                dp2[i][j] = up;
                dir2[i][j] = 1;
            }
            else
            {
                dp2[i][j] = left;
                dir2[i][j] = -1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int up = dp5[i - 1][j] + p5[i][j];
            int left = dp5[i][j - 1] + p5[i][j];
            if ((up < left || j == 1) && i != 1)
            {
                dp5[i][j] = up;
                dir5[i][j] = 1;
            }
            else
            {
                dp5[i][j] = left;
                dir5[i][j] = -1;
            }
        }
    }
    dir2[1][1] = dir5[1][1] = 0;
    if (min(dp2[n][n], dp5[n][n]) > 1 && found)
    {
        cout << "1\n";
        for (int i = 0; i < ind.second; i++)
            cout << "R";
        for (int i = 1; i < n; i++)
            cout << "D";
        for (int i = ind.second + 1; i < n; i++)
            cout << "R";
        cout << "\n";
        return;
    }
    if (dp2[n][n] < dp5[n][n])
        dr = dir2;
    else
        dr = dir5;
    vector<char> Dir;
    for (int i = n, j = n; dr[i][j];)
    {
        if (dr[i][j] == 1)
        {
            Dir.push_back('D');
            i--;
        }
        else if (dr[i][j] == -1)
        {
            Dir.push_back('R');
            j--;
        }
    }
    reverse(Dir.begin(), Dir.end());
    cout << min(dp2[n][n], dp5[n][n]) << "\n";
    for (auto i : Dir)
        cout << i;
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}