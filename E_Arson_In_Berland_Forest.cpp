#include <bits/stdc++.h>
using namespace std;
vector<string> given, ans;
vector<vector<int>> dist;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    dist = vector<vector<int>>(r + 2, vector<int>(c + 2, 100000000));
    given = vector<string>(r);
    for (auto &i : given)
        cin >> i;
    for (int i = 0; i <= c; i++)
        dist[0][i] = dist[r + 1][i] = 0;
    for (int i = 0; i <= r; i++)
        dist[i][0] = dist[i][c + 1] = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            if (given[i - 1][j - 1] == '.')
                dist[i][j] = 0;
            else
                dist[i][j] = min(dist[i][j], min({dist[i - 1][j], dist[i][j - 1], dist[i - 1][j - 1]}) + 1);
        }
    for (int i = 1; i <= r; i++)
        for (int j = c; j; j--)
        {
            if (given[i - 1][j - 1] == '.')
                dist[i][j] = 0;
            else
                dist[i][j] = min(dist[i][j], min({dist[i - 1][j], dist[i][j - 1], dist[i - 1][j - 1]}) + 1);
        }
    return 0;
}