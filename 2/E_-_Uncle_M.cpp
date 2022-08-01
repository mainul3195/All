#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int r, c;
    cin >> r >> c;
    vector<vector<long long>> org(r + 1, vector<long long>(c + 1, 0)), sq;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> org[i][j];
    sq = org;
    for (auto &i : sq)
        for (auto &j : i)
            j = j * j;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            org[i][j] = org[i][j] + org[i - 1][j] + org[i][j - 1] - org[i - 1][j - 1];

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            sq[i][j] = sq[i][j] + sq[i - 1][j] + sq[i][j - 1] - sq[i - 1][j - 1];

    int q;

    cin >> q;
    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        long long sqsum = sq[c][d] - sq[a - 1][d] - sq[c][b - 1] + sq[a - 1][b - 1];
        long long orgsum = org[c][d] - org[a - 1][d] - org[c][b - 1] + org[a - 1][b - 1];
        long long tot = (c - a + 1) * (d - b + 1);
        cout << fixed << setprecision(6) << (sqsum - (double)orgsum * orgsum / tot) / tot << "\n";
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}