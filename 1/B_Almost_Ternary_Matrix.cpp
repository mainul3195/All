#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v = {{1, 0, 0, 1}, {0, 1, 1, 0}};

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int ind = (i + 1) / 2 % 2;
        for (int j = 0; j + 4 <= m; j += 4)
            for (int k = 0; k < 4; k++)
                cout << v[ind][k] << " ";
        if (m % 4)
            cout << v[ind][0] << " " << v[ind][1];
        cout << "\n";
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